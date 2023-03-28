#!/bin/bash

prev_line=""
counter=1
max_line=""
max_counter=1

while read line; do
  if [[ "$line" == "$prev_line" ]]; then
    ((counter++))
  else
    if [[ "$counter" -gt "$max_counter" ]]; then
      max_counter="$counter"
      max_line="$prev_line"
    fi
    prev_line="$line"
    counter=1
  fi
done < "$1"

if [[ "$counter" -gt "$max_counter" ]]; then
  max_counter="$counter"
  max_line="$prev_line"
fi

if [[ "$max_counter" -gt 1 ]]; then
  echo "Line \"$max_line\" has the most consecutive occurrences ($max_counter times)"
  grep -B10 -A10 "$max_line" "$1"
fi

