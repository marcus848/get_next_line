#!/bin/bash
name="gnl.out"
objs="main.c get_next_line.c get_next_line_utils.c"
cc="gcc"
flags="-Wall -Wextra -Werror"
buffer=42

if [ -n "$1" ]; then
  buffer=$1
fi

$cc $flags -g -D BUFFER_SIZE=$buffer $objs -o $name
