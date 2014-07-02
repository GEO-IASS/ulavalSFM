#!/bin/bash

#INSTALL SCRIPT FOR LINUX

echo "#Added by ulavalSFM" >> $HOME/.bashrc
echo "export LD_LIBRARY_PATH="$PWD/lib/:$LD_LIBRARY_PATH"" >> $HOME/.bashrc
echo "[ Adding library path in .bashrc file ... done ]"

cd lib/opencv-2.4.9/
mkdir build/
cd build/
cmake -D CMAKE_INSTALL_PREFIX="../../../" -D CMAKE_LIBRARY_PATH="../../" -D CMAKE_INCLUDE_PATH="../../../include/" ..
make -j 2
make install
echo "[ Building OpenCV ... done ]"

cd ../../../src/
make -j 2
make install
echo "[ Building ulavalSFM ... done ]" 

echo "[ YOU CAN RUN ULAVALSFM ]"