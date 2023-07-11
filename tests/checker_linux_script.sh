#!/bin/bash

# Variables
TIMES_TO_RUN=10  # The number of times the program runs
ARG_SIZE=8  # The size of the ARG string of numbers
MIN_NUM=-50  # The minimum number in the range
MAX_NUM=50  # The maximum number in the range

# Function to generate a list of random numbers
generate_random_numbers() {
    for (( i=0; i<$ARG_SIZE; i++ ))
    do
        echo -n "$(( RANDOM % (MAX_NUM - MIN_NUM + 1) + MIN_NUM )) "  # Generate a random number within the range and append a space
    done
}

# Main loop to run the program
for (( i=0; i<$TIMES_TO_RUN; i++ ))
do
    ARG=$(generate_random_numbers)
    echo "Running with ARG: $ARG"
    ../push_swap $ARG | ../checker_linux $ARG
done
