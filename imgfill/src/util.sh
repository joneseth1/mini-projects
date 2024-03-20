#!/bin/bash

echo "Building..."
# Build the executable
g++ -o /c/programs/random-fun/mini-projects/imgfill/src/main /c/programs/random-fun/mini-projects/imgfill/src/main.cpp
# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

echo "Done Build"

echo "Running..."
# Run the executable
/c/programs/random-fun/mini-projects/imgfill/src/main
