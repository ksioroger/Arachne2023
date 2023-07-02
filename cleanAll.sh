#!/bin/bash

targets='PerfUtils CoreArbiter Arachne ArachnePerfTests'
for dir in $targets; do
    echo "Processing $dir ..."
    pushd $dir > /dev/null
    make clean
    popd > /dev/null
done
