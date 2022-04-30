# Boolean Benchmark Builder 

## About 

Boolean Benchmark Builder is a C++ tool that aims on the automatic generation of Boolean function benchmarks. Boolean function benchmarks are used to evaluate and analyze methods that are applied to program synthesis and evolvable hardware. The motivation for the development of the Boolean Benchmark Builder was the proposal and evaluation of two advanced phenotypic operators, called duplication and inversion, for the Genetic Programming variant Cartesian Genetic Programming in recent work which will be presentend at the Genetic and Evolutionary Computation Conference in Boston this year. The proposed methods have been evaluated on a diverse set of Boolean function benchmarks. The Boolean Benchmark Builder was used to generate the truth table of an arithmetic logical unit benchmark. This benchmark is described in the corresponding publication of this work (see reference below). 

## Cartesian Genetic Programming 

Genetic Programming is a heuristic method inspired by neo-Darwinian evolution that is commonly used for program synthesis. Cartesian Genetic Programming is a variant of Genetic Programming which uses an acyclic graph representation model. Cartesian Genetic Programming is predominantly applied to the synthesis of Boolean programs and to evolvable hardware.

## Citing this work

The preferred way to cite this work is

> Kalkreuth, R. (2022). “Phenotypic Duplication and Inversion in Carte-
> sian Genetic Programming applied to Boolean Function Learning”. In:
> Genetic and Evolutionary Computation Conference, Boston, USA, July
> 9-13, 2022, Companion Material Proceedings. Genetic and Evolution-
> ary Computation Conference 2022 (GECCO ’22). Boston, United States:
> ACM

or in BibTex:


```
@InProceedings{GECCO22,
  Title                    = {Phenotypic Duplication and Inversion in Cartesian Genetic Programming applied to Boolean Function Learning},
  Author                   = {Kalkreuth, Roman},
  Year                     = {2022},
  booktitle = {Genetic and Evolutionary Computation Conference, Boston, USA,
               July 9-13, 2022, Companion Material Proceedings},
  Address                  = {New York, NY, USA},
  Publisher                = {ACM},
  Series                   = {Genetic and Evolutionary Computation Conference 2022 (GECCO '22) },

  Location                 = {Boston, United States},
  Numpages                 = {4},
}

```

## Requirements 

C++11

## Links 

Cartesian Genetic Programming website: https://www.cartesiangp.com/

ECJ GitHub Repository: https://github.com/GMUEClab/ecj

Revised ECJ Contrib Package: https://github.com/RomanKalkreuth/ecj-contrib-cgp-revised
