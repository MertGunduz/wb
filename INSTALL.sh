#!/bin/bash

#****************************************
# BUILD DIRECTORY CREATION PART 
#****************************************
if [ ! -d "build" ]
then
    mkdir build
fi

echo "=%= build directory created =%="


#****************************************
# USR-DIRECTORY CONTROL PART 
#****************************************
if [ -d "$HOME/.wb" ] && [ -f "/usr/bin/wb" ] 
then
    # delete the files if they are exist in the system
    sudo rm -r "$HOME/.wb"
    sudo rm /usr/bin/wb
fi

echo "=%= file structure controlling =%="
sleep 1

#****************************************
# COMPILING AND LINKING PART 
#****************************************
if [ -d "build" ]
then
    # run cmake and go to build directory then run makefiles
    cmake -S . -B build
    cd build && make
fi

echo "=%= compiling and linking the project =%="
sleep 1

#****************************************
# MOVING THE EXECUTABLE TO USR/BIN PART
#****************************************
if [ ! -f "/usr/bin/wb" ]
then
    # move the wb executable to usr/bin (exexcutable place)
    sudo mv src/app/wb /usr/bin
fi

echo "=%= moving the executable to usr/bin =%="
sleep 1

#****************************************
# CREATING WB FOLDER TO HOME PART
#****************************************
if [ ! -d "$HOME/.wb" ]
then
    mkdir "$HOME/.wb"
    sudo chmod 775 "$HOME/.wb"
    touch "$HOME/.wb/words.txt"
    sudo chmod 775 "$HOME/.wb/words.txt"
fi

echo "=%= creating the wb folder to home =%="
sleep 1

#****************************************
# DELETING THE SOURCE BUILD DIRECTORY
#****************************************
cd .. && rm -r build

echo "=%= removing the build directory =%="
sleep 1

if [ -d "$HOME/.wb" ] && [ -f "/usr/bin/wb" ] && [ -f "$HOME/.wb/words.txt" ]
then 
    sudo echo "=%= wb installation succesful =%="
else
    sudo echo "=%= wb installation unsuccesful =%="
fi