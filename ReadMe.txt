Linux requirements:
clang
gcc
g++?
pck-config

Project requirements
libzmq
cppzmq
C++ 11

1. Build libzmq via cmake. This does an out of source build and installs the build files

download and unzip the lib, cd to directory
mkdir build
cd build
cmake ..
sudo make -j4 install

2. Build cppzmq via cmake. This does an out of source build and installs the build files

download and unzip the lib, cd to directory
mkdir build
cd build
cmake ..
sudo make -j4 install