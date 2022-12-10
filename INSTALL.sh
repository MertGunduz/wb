#!/bin/bash
DIR=./build

if [ -d "$DIR" ];
then
    mkdir build
fi

cmake -S . -B build

# goes to the build directory and runs make
cd ./build && make

# goes to the build/src/app folder and moves the mv folder to usr/bin (exexcutable place)
cd src/app/ && sudo mv wb /usr/bin

# creates a directory in usr/local
sudo mkdir /usr/local/wb