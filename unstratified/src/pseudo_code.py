#===============================================================================
# pseudo_code.py
#
# Pseudo code for the unstratified disk model.
#
# Author: Stanley A. Baronett
# Created: 2024-09-22
# Updated: 2024-09-22
#===============================================================================

import numpy as np

Nx, Ny, Nz = 512, 1, 512          # Number of cells in x, y, z
grid = np.zeros((Nx, Ny, Nz))     # Grid coordinates
rhog = np.zeros((Nx, Ny, Nz))     # Gas density
rhogu = np.zeros((3, Nx, Ny, Nz)) # Gas momenta along x, y, then z


# Lagrangian dust particles
np = 1
Np = np*Nx*Ny*Nz
particles = np.zeros(np)

def GasSourceTerms():
    """Adds source terms to the gas.

    Apply the Coriolis and centrifugal forces, and linear gravity from the star,
    and the background radial pressure gradient.
    """
    for k in grid[0, 0, :]:
        for j in grid[0, :, 0]:
            for i in grid[:, 0, 0]:
                Real rho_dt = prim(IDN,k,j,i) * dt
                cons(IM1,k,j,i) += rho_dt * (two_omega * prim(IVZ,k,j,i) + gas_accel_x);
                cons(IM3,k,j,i) -= rho_dt * omega_half * prim(IVX,k,j,i)

def DustFluidSourceTerms():
    """Adds source terms to the dust fluid.

    Apply the Coriolis and centrifugal forces and linear gravity from the star.
    """
    for k in grid[0, 0, :]:
        for j in grid[0, :, 0]:
            for i in grid[:, 0, 0]:
                Real rho_dt = prim(IDN,k,j,i) * dt
                cons(IM1,k,j,i) += rho_dt * (two_omega * prim(IVZ,k,j,i) + gas_accel_x);
                cons(IM3,k,j,i) -= rho_dt * omega_half * prim(IVX,k,j,i)

def DustParticles():
    """
    """
    for i in particles:
        dvpx[k] += two_omega * vpz[k];
        dvpz[k] -= omega_half * vpx[k];
