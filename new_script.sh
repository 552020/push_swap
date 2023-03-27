#!/bin/bash

if [[ "$#" -lt 1 ]]; then
  echo "Usage: $0 filename [exclude_line1] [exclude_line2] ..."
  exit 1
fi

filename="$1"
shift
excluded_lines=("$@") # store excluded lines in an array

if [[ ! -f "$filename" ]]; then
  echo "Error: \"$filename\" does not exist or is not a file"
  exit 1
fi

declare -A counts

while read line; do
  if [[ "${excluded_lines[@]}" =~ "$line" ]]; then
    continue # skip excluded lines
  fi

  if [[ "$line" == "$prev_line" ]]; then
    ((counts[$line]++))
  else
    prev_line="$line"
    counts["$line"]=1
  fi
done < "$filename"

max_count=0
max_line=""
for line in "${!counts[@]}"; do
  count="${counts[$line]}"
  if [[ "$count" -gt "$max_count" ]]; then
    max_count="$count"
    max_line="$line"
  fi
done

echo "Line \"$max_line\" occurs $max_count times consecutively"
grep -B10 -A10 "$max_line" "$filename"

