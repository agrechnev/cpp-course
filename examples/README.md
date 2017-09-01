C++ course examples by Oleksiy Grechnyev

Each subdirectory contains one example

e3_2 means lecture 3 example 2

To build all examples, type in this directory

mkdir build

cd build

cmake ..

cmake --build .

If using MinGW, you will need to specify CMake the generator for gcc

mkdir build

cd build

cmake -G "MinGW Makefiles" ..

cmake --build .