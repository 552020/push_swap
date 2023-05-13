#!/bin/bash

# Variables
total_numbers=5
total_lines=0
highest_value=-1
lowest_value=-1
total_runs=100  # Number of runs
numbers_file="numbers.txt"  # File to store the randomly generated numbers

# Function to generate random numbers and execute push_swap
run_push_swap() {
    # local numbers=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
	local numbers=$(shuf -i 1-$total_numbers -n $total_numbers | tr '\n' ' ')
    echo "$numbers" > $numbers_file
    local lines=$(./push_swap $numbers | wc -l)
    rm $numbers_file
    echo $lines
}

# Loop for multiple runs
for ((i=1; i<=$total_runs; i++)); do
    echo "Run $i:"
    lines=$(run_push_swap)
    total_lines=$((total_lines + lines))

    # Update highest value
    if [ $lines -gt $highest_value ] || [ $highest_value -eq -1 ]; then
        highest_value=$lines
    fi

    # Update lowest value
    if [ $lines -lt $lowest_value ] || [ $lowest_value -eq -1 ]; then
        lowest_value=$lines
    fi

    echo "Lines: $lines"
    echo
done

# Calculate average
average=$((total_lines / total_runs))

# Print results
echo "Highest value: $highest_value"
echo "Lowest value: $lowest_value"
echo "Average: $average"
