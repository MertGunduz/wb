#!/bin/bash

#****************************************
# BUILD DIRECTORY CREATION [1]
#****************************************
if [ ! -d "build" ]
then
    mkdir build

    echo "=%= build directory created =%="
fi


#****************************************
# USR-DIRECTORY CONTROL [2] 
#****************************************
if [ -d "$HOME/.wb" ] && [ -f "/usr/bin/wb" ] 
then
    # delete the files if they are exist in the system
    sudo rm -r "$HOME/.wb"
    sudo rm /usr/bin/wb

    echo "=%= file structure controlling =%="
    sleep 1
fi

#******************************************
# USR/SHARE/MAN DIRECTORY CONTROL [3]
#******************************************
if [ -f "/usr/share/man/man1/wb.1.gz" ]
then
    sudo rm /usr/share/man/man1/wb.1.gz

    echo "=%= man file controlling =%="
    sleep 1
fi

#****************************************
# COMPILING AND LINKING [4]
#****************************************
if [ -d "build" ]
then
    # run cmake and go to build directory then run makefiles
    cmake -S . -B build
    cd build && make

    # man page generation
    cp ../man/wb.1 wb.1

    echo "=%= compiling and linking the project =%="
    sleep 1
fi

#****************************************
# MOVING THE EXECUTABLE TO USR/BIN [5]
#****************************************
if [ ! -f "/usr/bin/wb" ]
then
    # move the wb executable to usr/bin (exexcutable place)
    sudo mv src/app/wb /usr/bin
    sudo mv wb.1 /usr/share/man/man1
    sudo gzip /usr/share/man/man1/wb.1

    echo "=%= moving the executable to usr/bin =%="
    sleep 1
fi

#****************************************
# CREATING WB FOLDER TO HOME [6]
#****************************************
if [ ! -d "$HOME/.wb" ]
then
    mkdir "$HOME/.wb"
    sudo chmod 775 "$HOME/.wb"
    touch "$HOME/.wb/words.txt"
    sudo chmod 775 "$HOME/.wb/words.txt"

    echo "=%= creating the wb folder to home =%="
    sleep 1
fi

#****************************************
# DELETING THE SOURCE BUILD DIRECTORY [7]
#****************************************
cd .. && rm -r build

echo "=%= removing the build directory =%="
sleep 1

if [ -d "$HOME/.wb" ] && [ -f "/usr/bin/wb" ] && [ -f "$HOME/.wb/words.txt" ] && [  -f "/usr/share/man/man1/wb.1.gz" ]
then 
    sudo echo "=%= wb installation succesful =%="
else
    sudo echo "=%= wb installation unsuccesful =%="
fi