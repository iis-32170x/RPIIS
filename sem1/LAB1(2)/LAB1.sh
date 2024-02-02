#!/bin/bash

echo "Enter the date (MM/DD/YYYY)"
read data
WDAY=$(date -d"$data" +%A)

echo "$WDAY"

