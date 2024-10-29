# Streaming Instability Code Comparison (SICC)

Project and source files related to the Streaming Instability Code Comparison ([SICC](https://pfitsplus.github.io/research/code-comparison/)) led by [PFITS+](https://pfitsplus.github.io/) and the [UFOS Project](https://www.ufos-project.eu/).
The underlying figure data can be found at the project's [Google Shared Drive](https://drive.google.com/drive/folders/14GiJq2lyPePPaCrZzzELsCou5rLTza0v?usp=sharing) (please contact [Stanley A. Baronett](https://pfitsplus.github.io/team/baronett-stanley/) to request access to add or edit files).
For more information and project updates, please visit our [dedicated webpage](https://pfitsplus.github.io/research/code-comparison/).


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
To be consistent with the structure of the Streaming Instability Code Comparison Problem Set document (see Section 1.2), the subdirectories within are hierarchically organized first by *model* (e.g., [`/unstratified`](/tree/main/ipynb/unstratified)), next by *problem* (e.g., [`../BA`](/tree/main/ipynb/unstratified/BA)), and last by *variation* (e.g., [`../../np1`](/tree/main/ipynb/unstratified)).


### Source files

Source and input files for some participating codes, as well as pseudo code for particular models (e.g., [`../unstratified/pseudo_code.py`](/tree/main/source_files/unstratified/pseudo_code.py)), can be found in the [`/source_files`](/tree/main/ipynb) directory.
To be consistent with the structure of the Streaming Instability Code Comparison Problem Set document (see Section 1.2), the subdirectories within are hierarchically organized first by *model* (e.g., [`/unstratified`](/tree/main/ipynb/unstratified)), next by *problem* (e.g., [`../BA`](/tree/main/ipynb/unstratified/BA)), next by *variation* (e.g., [`../../np1`](/tree/main/ipynb/unstratified)), and last by *code* (e.g., [`../../../Athena++`](/tree/main/ipynb/unstratified)).
