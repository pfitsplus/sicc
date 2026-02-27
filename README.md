# Streaming Instability Code Comparison

This repository hosts figure scripts and source code files for the <a href="https://pfitsplus.github.io/research/code-comparison/" target="_blank">Streaming Instability Code Comparison</a> project led by <a href="https://pfitsplus.github.io/" target="_blank">PFITS+</a>.
The underlying figure data is hosted on our <a href="https://drive.google.com/drive/folders/14GiJq2lyPePPaCrZzzELsCou5rLTza0v?usp=sharing" target="_blank">Google Shared Drive</a> (please contact <a href="https://pfitsplus.github.io/team/baronett-stanley/" target="_blank">Stanley A. Baronett</a> to request access to add files).
For project updates and details on how to contribute, please visit our <a href="https://pfitsplus.github.io/research/code-comparisons/" target="_blank">dedicated webpage</a>.


## Directory structure

To be consistent with the structure of the <a href="https://pfitsplus.github.io/assets/docs/research/code-comparison/si/sicc_problem_set.pdf" target="_blank">Problem Set</a> (Section 1.2), the subdirectories are hierarchically organized first by *model* (e.g., [`/unstratified`](https://github.com/pfitsplus/sicc/tree/main/unstratified)), next by *problem* (e.g., [`../BA`](https://github.com/pfitsplus/sicc/tree/main/unstratified/BA)), and last by *variation* (e.g., [`../../512`](https://github.com/pfitsplus/sicc/tree/main/unstratified/BA/512)).


### Tree view

```
/[model]
  /src
    /pseudo_code.py
    /[dust_implementation]
      /[code]
        /[source files]
  /[problem]
    /[variation]
      /[figures].ipynb
      /src
        /[dust_implementation]
          /[code]
            /[source/input files]
```


### Figures

<a href="https://jupyter.org/" target="_blank">Jupyter Notebooks</a> (with filename extension `.ipynb`) containing <a href="https://www.python.org/" target="_blank">Python</a> scripts to generate <a href="https://pfitsplus.github.io/research/code-comparison/#figures" target="_blank">figures</a> can be found within the subdirectories (see [tree view](#tree-view)).


### Source code

Source and input files for contributing codes can be found within any `/src/` subdirectory (see [tree view](#tree-view)).
To contribute these files, please create a [pull request](https://github.com/pfitsplus/sicc/pulls) from your own [fork](https://github.com/pfitsplus/sicc/fork).


## Issues

Please feel free to [create an issue](https://github.com/pfitsplus/sicc/issues) for any questions, feedback, or issues encountered.
