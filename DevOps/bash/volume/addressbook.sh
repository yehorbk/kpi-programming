#!/bin/bash

command="$1"

filename=".addressbook"

get_all () {
  cat "$filename" 2> /dev/null
}

get_match () {
  get_all | grep "$1"
}

new () {
  name="$1"
  email="$2"
  echo "$name $email" >> "$filename"
}

list () {
  data=$(get_all)
  if [ -z "$data" ]
  then
    echo "address book is empty"
    exit
  fi
  echo "$data"
}

remove () {
  name="$1"
  entries=$(get_match "$name")
  echo "$entries" | xargs -I "{}" sed -i "/{}/d" "$filename" 2> /dev/null
}

clear() {
  echo -n "" > "$filename"
}

lookup() {
  name="$1"
  regexp="\b\S*@\S*\.\S*\b"
  echo "$(get_match "$name")" | grep -o "$regexp"
}

if [ $command = "new" ]
then
  new "$2" "$3"
elif [ $command = "list" ]
then
  list
elif [ $command = "remove" ]
then
  remove "$2"
elif [ $command = "clear" ]
then
  clear
elif [ $command = "lookup" ]
then
  lookup "$2"
fi
