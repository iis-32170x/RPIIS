#!/usr/bin/env bash

if [[ ! -d "$1" ]]; then
  echo "$1: No such directory"
  exit 1
fi

find "$1" -type f -user "$2" -newerct "$3" ! -newerct "$4" >> result.txt