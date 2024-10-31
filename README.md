# Streaming Instability Code Comparison

This repository hosts figure scripts and source codes for the [Streaming Instability Code Comparison](https://pfitsplus.github.io/research/code-comparison/) project led by [PFITS+](https://pfitsplus.github.io/).
The underlying figure data is hosted on our [Google Shared Drive](https://drive.google.com/drive/folders/14GiJq2lyPePPaCrZzzELsCou5rLTza0v?usp=sharing) (please contact [Stanley A. Baronett](https://pfitsplus.github.io/team/baronett-stanley/) to request access to add files).
For project updates and details on how to contribute, please visit our [dedicated webpage](https://pfitsplus.github.io/research/code-comparison/).


## Directory structure

### Tree view

```
/ipynb
  /[model]
    /[problem]
      /[variation]
        /[figure notebooks]
/source_files
  /[model]
    /codes
      /[code]
        /[source files]
    /[problem]
      /[variation]
        /[code]
          /[input files]
    /pseudo_code.py
```

### Figures

[Jupyter Notebooks](https://jupyter.org/) containing [Python](https://www.python.org/) scripts to generate the manuscript figures can be found in the [`/ipynb`](/tree/main/ipynb) directory.
To be consistent with the structure of the [Problem Set](https://pfitsplus.github.io/assets/docs/research/code-comparison/si/sicc_problem_set.pdf) (Section 1.2), the subdirectories within are hierarchically organized first by *model* (e.g., [`/unstratified`](/tree/main/ipynb/unstratified)), next by *problem* (e.g., [`../BA`](/tree/main/ipynb/unstratified/BA)), and last by *variation* (e.g., [`../../np1`](/tree/main/ipynb/unstratified)).


### Source code

Source and input files for some contributing codes can be found in the [`/source_files`](/tree/main/ipynb) directory.
To be consistent with the structure of the [Problem Set](https://pfitsplus.github.io/assets/docs/research/code-comparison/si/sicc_problem_set.pdf) (Section 1.2), the subdirectories within are hierarchically organized first by *model* (e.g., [`/unstratified`](/tree/main/ipynb/unstratified)), next by *problem* (e.g., [`../BA`](/tree/main/ipynb/unstratified/BA)), next by *variation* (e.g., [`../../np1`](/tree/main/ipynb/unstratified)), and last by *code* (e.g., [`../../../Athena++`](/tree/main/ipynb/unstratified)).
