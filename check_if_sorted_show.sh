#!/bin/bash

# This script checks if the input is sorted in ascending order

# read input into an array
declare -a nums=()
while read -r line; do
  nums+=("$line")
done

# check if the array is sorted
if echo "${nums[@]}" | tr ' ' '\n' | sort -C; then
  # return code 0
  echo "sorted"
else
  # return code not 0
  echo "not sorted"

  # find the first unsorted element
  unsorted=$(echo "${nums[@]}" | awk '{for(i=2;i<=NF;i++)if($i<$((prev=$i-1)))print prev}')

  # output the first unsorted element
  echo "First unsorted element: $unsorted"
fi

