#!/bin/bash
#this script is part of the colorado boulder linux intro course
#this script will show you how to use the find command to search for files
filesdir=$1
searchstr=$2
if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "Please set the directory you want to search in and the string you want to search for"
    exit 1
fi
if [ ! -d "$filesdir" ]; then
    echo "Please set a valid directory to search in"
    exit 1
fi
numfiles=$(find "$filesdir" -type f | wc -l)
numlines=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)
echo "The number of files are $numfiles and the number of matching lines are $numlines"