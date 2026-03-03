#include <stdlib.h>
#include "idefix.hpp"
#include "setup.hpp"
#include "real_types.hpp"
#include <cmath>

float randm() {
  return ((float)rand()/RAND_MAX);
}
static real omega;
static real shear;
real epsilon;
const int ns=1;   // number of dust species. compile time at the moment but will change later to run time
real chi[ns];
real tauGlob[ns];
real chi_tot;
real cs;



#define  FILENAME    "timevol.dat"

//#define STRATIFIED
void PressureGradient(Hydro *hydro, const real t, const real dt) {
  auto Uc = hydro->Uc;
  auto Vc = hydro->Vc;
  DataBlock *data = hydro->data;
  real eps = epsilon;
  idefix_for("MySourceTerm",0,data->np_tot[KDIR],0,data->np_tot[JDIR],0,data->np_tot[IDIR],
              KOKKOS_LAMBDA (int k, int j, int i) {
                // Radial pressure gradient
                  Uc(MX1,k,j,i) += eps*Vc(RHO,k,j,i)*dt;
                  //Uc(MX1,k,j,i) += eps*dt;
              });
}

void BodyForce(DataBlock &data, const real t, IdefixArray4D<real> &force) {
  idfx::pushRegion("BodyForce");
  IdefixArray1D<real> x = data.x[IDIR];
  IdefixArray1D<real> z = data.x[KDIR];

  // GPUS cannot capture static variables
  real omegaLocal=omega;
  real shearLocal =shear;

  idefix_for("BodyForce",
              data.beg[KDIR] , data.end[KDIR],
              data.beg[JDIR] , data.end[JDIR],
              data.beg[IDIR] , data.end[IDIR],
              KOKKOS_LAMBDA (int k, int j, int i) {

                force(IDIR,k,j,i) = -2.0*omegaLocal*shearLocal*x(i);
                force(JDIR,k,j,i) = ZERO_F;
                force(KDIR,k,j,i) = ZERO_F;

      });


  idfx::popRegion();
}

// Analyse data to produce an output
void Analysis(DataBlock & data) {


// Mirror data on Host
  DataBlockHost d(data);
  // Sync it
  d.SyncFromDevice();
  real rho = d.dustVc[0](RHO,0,0,0);
  for(int k = 0; k < d.np_tot[KDIR] ; k++) {
    for(int j = 0; j < d.np_tot[JDIR] ; j++) {
      for(int i = 0; i < d.np_tot[IDIR] ; i++) {
        if(rho < d.dustVc[0](RHO,k,j,i)) {
          rho=d.dustVc[0](RHO,k,j,i);
        }
      }
    }
  }
  #ifdef WITH_MPI
  real rho_max;
  MPI_Reduce(&rho, &rho_max, 1, realMPI, MPI_MAX, 0, MPI_COMM_WORLD);
  #endif
  if(idfx::prank == 0) {
  std::ofstream f;
  f.open(FILENAME,std::ios::app);
  f.precision(10);
  #ifdef WITH_MPI
  f << std::scientific << data.t/6.283 << "	" << rho_max << "	" << std::endl;
  #else
  f << std::scientific << data.t/6.283 << "	" << rho << "	" << std::endl;
  #endif
  f.close();
  }

}

// Initialisation routine. Can be used to allocate
// Arrays or variables which are used later on
Setup::Setup(Input &input, Grid &grid, DataBlock &data, Output &output) {
  // Get rotation rate along vertical axis
  omega=input.Get<real>("Hydro","rotation",0);
  shear=input.Get<real>("Hydro","shearingBox",0);
  cs=input.Get<real>("Hydro","csiso",1);
  int nSpecies = data.dust.size();
  epsilon = input.Get<real>("Setup","epsilon",0);
  chi_tot = 0.0;
  for(int n = 0 ; n < nSpecies ; n++) {
      tauGlob[n] = input.Get<real>("Dust","drag",n+1);
      chi[n] = input.Get<real>("Setup","chi",n);
      chi_tot = chi_tot + chi[n];
    }
  data.hydro->EnrollUserSourceTerm(&PressureGradient);
  // Add our userstep to the timeintegrator
   data.gravity->EnrollBodyForce(BodyForce);

  output.EnrollAnalysis(&Analysis);

}

// This routine initialize the flow
// Note that data is on the device.
// One can therefore define locally
// a datahost and sync it, if needed
void Setup::InitFlow(DataBlock &data) {
    // Create a host copy
    DataBlockHost d(data);

    real taus = tauGlob[0]*omega;
    real D = 1+chi_tot;

    srand(idfx::prank);
    for(int k = 0; k < d.np_tot[KDIR] ; k++) {
        for(int j = 0; j < d.np_tot[JDIR] ; j++) {
            for(int i = 0; i < d.np_tot[IDIR] ; i++) {
                real x=d.x[IDIR](i);
                real dx= 0.001953125;
                real xmin=x-dx;
                real z=d.x[KDIR](k);
                real dz= 0.001953125;
                real zmin=z-dz;
                d.Vc(RHO,k,j,i) = 1.0;
                d.Vc(VX1,k,j,i) = 0.16393442622950818*epsilon/2.0;
                d.Vc(VX2,k,j,i) = -0.901639344262295*epsilon/2.0;
                d.Vc(VX1,k,j,i) += 2e-2*cs*(idfx::randm()-0.5);
                d.Vc(VX2,k,j,i) += shear*x+2e-2*cs*(idfx::randm()-0.5);
                d.Vc(VX3,k,j,i) += +2e-2*cs*(idfx::randm()-0.5);
                d.dustVc[0](RHO,k,j,i) = 0.2;
                d.dustVc[0](VX1,k,j,i) = -0.8196721311475409*epsilon/2.0+2e-2*cs*(idfx::randm()-0.5);
                d.dustVc[0](VX2,k,j,i) = -0.4918032786885245*epsilon/2.0+2e-2*cs*(idfx::randm()-0.5);
                d.dustVc[0](VX2,k,j,i) += shear*x;
                d.dustVc[0](VX3,k,j,i) =  0.0 +2e-2*cs*(idfx::randm()-0.5);
            }
        }
    }

    // Send it all, if needed
    d.SyncToDevice();
}


// Analyse data to produce an output

void MakeAnalysis(DataBlock & data) {
}
