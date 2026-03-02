#!/bin/bash
# run_project4.sh
# shell script that runs everything needed for Project #4

make clean
make
echo ""
echo "Running Crank-Nicolson method to solve 1D Heat Diffusion:"
echo "Creating results data files..."
initialization="gaussian"

if [ -z "$1" ]; then
    echo "Warning: Provide the initialization function as the argument"
    echo "Using the gaussian initialization as the default"
else
    if [[ "$1" != "gaussian" && "$1" != "sin" && "$1" != "quadratic" ]]; then
        echo "Only gaussian, sin, or quadratic values are allowed"
        exit 1;
    else
        initialization="$1"
    fi
fi

./CrankNicolson "$initialization"
echo ""
echo "run 'gnuplot plot.gnu' to create the graph"
echo "The graph will be stored in graph.pdf file"