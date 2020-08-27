#!/bin/bash

#function-ify the build script
function buildRunProg () {
    
    # build
    ./build.sh
    
    # run
    ./run.sh
}

# tee the output to both stdout and stderr
buildRunProg | tee buildRunOutput.txt