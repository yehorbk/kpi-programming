#!/bin/bash

path=$1
old_ext=$2
new_ext=$3

files=$(ls $path/*.$old_ext 2> /dev/null)

if [ -z "$files" ];
then
  echo "No files with extension $old_ext in directory $path"
  exit
fi

echo "Batch rename start"
echo "$files" | sed "p;s/.$old_ext/.$new_ext/g" | xargs -n2 bash -c 'echo "$0 -> $1" && mv $0 $1'
echo "Batch rename end"
