#!/bin/bash
DIR=./build

if [ -d "$DIR" ];
then
    mkdir build
fi

cmake -S . -B build