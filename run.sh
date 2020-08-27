#!/bin/bash

#function-ify the build script
function runProg () {
    # run
    ./a.out
}

# tee the output to both stdout and stderr
runProg | tee output.txt