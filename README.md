# DLF

## Description

## Features

## Installation

## Useage

## Develop log

### 1. configure the enviroment

what we need is xtensor in c++ and related lib.
make a directory in your porject like DLF/lib. then git clone the following reporsitory in git hub.
if you are to find an easy way just copy the code behind it and execute the code, it also works.

- xtensor `git clone https://github.com/xtensor-stack/xtensor.git`
- xtensor-blas `git clone https://github.com/xtensor-stack/xtensor-blas.git`
- xtensor-python `git clone https://github.com/xtensor-stack/xtensor-python.git`
- xtl `git clone https://github.com/xtensor-stack/xtl.git`

next turn to vs add them include file to the contain.

### 2. datatype node and calculate node

more details see [here](https://www.cnblogs.com/devilmaycry812839668/p/16900550.html)

* datatype.h support common data type
* node.hpp support two nodes: __DATA_NODE__ and __CALC_NODE__

here is the draft I'll replace it by my own picture.
![alt text](<Screenshot 2024-08-04 215047.png>)


