#!/bin/bash

#function-ify the build script
function buildProg () {

    # filename
    FILENAME="../matrixGen.cpp"

    # compile c++
    g++ -pthread -o a.out $FILENAME -lglfw -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl
}

# tee the output to both stdout and stderr
buildProg | tee buildOutput.txt