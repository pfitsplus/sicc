# Streaming Instability Code Comparison

This repository hosts figure scripts and source code files for the [Streaming Instability Code Comparison](https://pfitsplus.github.io/research/code-comparison/){:target="_blank"} project led by [PFITS+](https://pfitsplus.github.io/){:target="_blank"}.
The underlying figure data is hosted on our [Google Shared Drive](https://drive.google.com/drive/folders/14GiJq2lyPePPaCrZzzELsCou5rLTza0v?usp=sharing){:target="_blank"} (please contact [Stanley A. Baronett](https://pfitsplus.github.io/team/baronett-stanley/){:target="_blank"} to request access to add files).
For project updates and details on how to contribute, please visit our [dedicated webpage](https://pfitsplus.github.io/research/code-comparison/){:target="_blank"}.


## Directory structure

To be consistent with the structure of the [Problem Set](https://pfitsplus.github.io/assets/docs/research/code-comparison/si/sicc_problem_set.pdf){:target="_blank"} (Section 1.2), the subdirectories are hierarchically organized first by *model* (e.g., [`/unstratified`](/tree/main/ipynb/unstratified)), next by *problem* (e.g., [`../BA`](/tree/main/ipynb/unstratified/BA)), and last by *variation* (e.g., [`../../512`](/tree/main/ipynb/unstratified)).


### Tree view

```
/[model]
  /[problem]
    /[variation]
      /[figures].ipynb
      /src
        /[dust_implementation]
          /[code]
            /[source/input files]
  /src
    /pseudo_code.py
    /[dust_implementation]
      /[code]
        /[source files]
```

### Figures

[Jupyter Notebooks](https://jupyter.org/){:target="_blank"} (with filename extension `.ipynb`) containing [Python](https://www.python.org/){:target="_blank"} scripts to generate [figures]() can be found within the subdirectories (see [tree view](#tree-view)).


### Source code

Source and input files for contributing codes can be found within any `/src/` subdirectory (see [tree view](#tree-view)).
