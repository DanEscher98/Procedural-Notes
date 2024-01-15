#!/bin/bash

filename="$1"   # Get filename from command line argument

while IFS= read -r -n1 char
do
  if [[ $char =~ [^[:ascii:]] ]]; then   # Check if character is non-ASCII
    printf '&#%d;' "$(printf '%d' "'$char")"  # Convert to decimal Unicode and print
  else
    printf '%s' "$char"  # If ASCII, just print the character as it is
  fi
done < "$filename"
