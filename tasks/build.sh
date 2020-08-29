#!/bin/bash

#function-ify the build script
function buildProg () {
    # compile c++
    g++ -pthread -o a.out matrixGen.cpp -lglfw -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl
}

# tee the output to both stdout and stderr
buildProg | tee buildOutput.txt