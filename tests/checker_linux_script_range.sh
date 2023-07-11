#!/bin/bash

# Variables
TIMES_TO_RUN=20  # The number of times the program runs
MIN_ARG_SIZE=5  # The minimum size of the ARG string of numbers
MAX_ARG_SIZE=11  # The maximum size of the ARG string of numbers
MIN_NUM=-50  # The minimum number in the range
MAX_NUM=50  # The maximum number in the range
KO_SUMMARY=""  # Stores the summary of 'KO' outputs

# Function to generate a list of random numbers
generate_random_numbers() {
    ARG_SIZE=$1
    for (( i=0; i<$ARG_SIZE; i++ ))
    do
        echo -n "$(( RANDOM % (MAX_NUM - MIN_NUM + 1) + MIN_NUM )) "  # Generate a random number within the range and append a space
    done
}

# Main loop to run the program
for (( ARG_SIZE=$MIN_ARG_SIZE; ARG_SIZE<=$MAX_ARG_SIZE; ARG_SIZE++ ))
do
    for (( i=0; i<$TIMES_TO_RUN; i++ ))
    do
        ARG=$(generate_random_numbers $ARG_SIZE)
        PRESENT_LINE="Running with $ARG_SIZE ARG: $ARG"
        echo "$PRESENT_LINE"
        OUTPUT=$(../push_swap $ARG | ../checker_linux $ARG)
        echo "$OUTPUT"
        if [[ $OUTPUT == *"KO"* ]]; then
            KO_SUMMARY+="$PREVIOUS_LINE\n$OUTPUT\n"
        fi
        PREVIOUS_LINE=$PRESENT_LINE
    done
done

# Print the summary of 'KO' outputs
echo -e "\nSummary of 'KO' outputs:"
echo -e "$KO_SUMMARY"
