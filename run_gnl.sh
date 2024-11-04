#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: ./run_gnl.sh <BUFFER_SIZE>"
  exit 1
fi

gcc -Wall -Wextra -Werror -D BUFFER_SIZE="$1" main.c get_next_line.c get_next_line_utils.c -o gnl && ./gnl
