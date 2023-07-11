#!/bin/bash

# Variables
ARG_SIZE=10  # The size of the ARG string of numbers
INT_MAX=2147483647  # Maximum integer value
INT_MIN=-2147483648  # Minimum integer value

# Function to generate a list of random numbers with a specific outlier
generate_random_numbers() {
    OUTLIER=$1
    for (( i=0; i<$((ARG_SIZE - 1)); i++ ))
    do
        echo -n "$(( RANDOM % 200 - 100 )) "  # Generate a random number within the range and append a space
    done
    echo -n "$OUTLIER "  # Add the outlier
}

# Run with number greater than INT_MAX
ARG=$(generate_random_numbers $((INT_MAX + 1)))
echo "Running with ARG: $ARG"
../push_swap $ARG | ../checker_linux $ARG

# Run with number smaller than INT_MIN
ARG=$(generate_random_numbers $((INT_MIN - 1)))
echo "Running with ARG: $ARG"
../push_swap $ARG | ../checker_linux $ARG
