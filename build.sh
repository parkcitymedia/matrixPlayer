#!/bin/bash

# compile c++
g++ -pthread -o a.out main.cpp -lglfw -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl

#function-ify the build script
function runProg () {
    # run
    ./a.out
}

# make a new output every time because tee appends by default
rm output.txt

# tee the output to both stdout and stderr
runProg | tee output.txt