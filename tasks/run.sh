#!/bin/bash

#function-ify the build script
function runProg () {
    # run
    ./a.out
}

# output directory
OUTPUTDIR="../tasks"

# tee the output to both stdout and stderr
runProg | tee $OUTPUTDIR/runOutput.txt