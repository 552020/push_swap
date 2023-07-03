#!/bin/bash

# Variables
total_runs=1  # Number of runs
numbers_sizes=(1 3 5 7 10 100 500)  # Sizes of number sets
program="../push_swap"  # The program to test
leaks_file="leaks.txt"  # File to store the Valgrind output

# Function to generate random numbers, execute push_swap, and check for leaks
run_valgrind() {
    local numbers=$(shuf -i 1-$1 -n $1 | tr '\n' ' ')
    echo "$numbers" > $numbers_file
    valgrind --leak-check=full --log-file=$leaks_file $program $numbers
    grep "ERROR SUMMARY:" $leaks_file
    rm $numbers_file
}

# Loop over different sizes
for size in ${numbers_sizes[@]}; do
    echo "Size: $size"

    # Loop for multiple runs
    for ((i=1; i<=$total_runs; i++)); do
        echo "Run $i:"
        run_valgrind $size
        echo
    done
done

# Remove the Valgrind output file
rm $leaks_file
