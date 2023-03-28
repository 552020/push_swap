#!/bin/bash

if [[ "$#" -lt 2 ]]; then
  echo "Usage: $0 filename num_consecutive_occurrences"
  exit 1
fi

filename="$1"
num_occurrences="$2"

if [[ ! -f "$filename" ]]; then
  echo "Error: \"$filename\" does not exist or is not a file"
  exit 1
fi

if [[ "$num_occurrences" -lt 1 ]]; then
  echo "Error: num_consecutive_occurrences must be a positive integer"
  exit 1
fi

occurrences=()
while read line; do
  if [[ "$line" == "$prev_line" ]]; then
    ((counter++))
  else
    if [[ "$counter" -gt 1 ]]; then
      occurrences+=("$counter $prev_line")
    fi
    prev_line="$line"
    counter=1
  fi
done < "$filename"

if [[ "$counter" -gt 1 ]]; then
  occurrences+=("$counter $prev_line")
fi

if [[ "${#occurrences[@]}" -lt "$num_occurrences" ]]; then
  echo "Error: there are fewer than $num_occurrences lines with consecutive occurrences"
  exit 1
fi

IFS=$'\n' sorted_occurrences=($(sort -r <<<"${occurrences[*]}"))
unset IFS

target_occurrence="${sorted_occurrences[$((num_occurrences-1))]}"
target_count="${target_occurrence%% *}"
target_line="${target_occurrence#* }"

echo "Line \"$target_line\" has the ${num_occurrences}nd greatest number of consecutive occurrences ($target_count times)"
grep -B10 -A10 "$target_line" "$filename"

