#!/bin/bash

if [[ "$#" -lt 1 ]]; then
  echo "Usage: $0 filename"
  exit 1
fi

filename="$1"

if [[ ! -f "$filename" ]]; then
  echo "Error: \"$filename\" does not exist or is not a file"
  exit 1
fi

prev_line=""
counter=1
max_line=""
max_counter=1
second_max_line=""
second_max_counter=1

while read line; do
  if [[ "$line" == "$prev_line" ]]; then
    ((counter++))
  else
    if [[ "$counter" -gt "$max_counter" ]]; then
      second_max_counter="$max_counter"
      second_max_line="$max_line"
      max_counter="$counter"
      max_line="$prev_line"
    elif [[ "$counter" -gt "$second_max_counter" ]]; then
      second_max_counter="$counter"
      second_max_line="$prev_line"
    fi
    prev_line="$line"
    counter=1
  fi
done < "$filename"

if [[ "$counter" -gt "$max_counter" ]]; then
  second_max_counter="$max_counter"
  second_max_line="$max_line"
  max_counter="$counter"
  max_line="$prev_line"
elif [[ "$counter" -gt "$second_max_counter" ]]; then
  second_max_counter="$counter"
  second_max_line="$prev_line"
fi

if [[ "$second_max_counter" -gt 1 ]]; then
  echo "Line \"$second_max_line\" has the second most consecutive occurrences ($second_max_counter times)"
  grep -B10 -A10 "$second_max_line" "$filename"
else
  echo "No line has more than one consecutive occurrence"
fi

