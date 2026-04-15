#!/bin/bash
writefile=$1
writestr=$2
if [ -z "$writefile" ]; then
  echo "only full path to a file is allowed, not a directory"
  exit 1
fi
if [ -z "$writestr" ]; then
  echo "only String is allowed to write to file, not empty string"
  exit 1
fi
mkdir -p "$(dirname "$writefile")"
echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: could not create file $writefile"
    exit 1
fi