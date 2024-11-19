#!/bin/bash
name="gnl.out"
objs="main.c get_next_line.c get_next_line_utils.c"
objsbonus="main.c get_next_line_bonus.c get_next_line_utils_bonus.c"
objsfinal="$objs"
cc="gcc"
flags="-Wall -Wextra -Werror"
buffer=42

if [ -n "$1" ]; then
	if [ $1 = "-bonus" ]; then
		objsfinal="$objsbonus"
	else
		buffer=$1
	fi
fi

if [ -n "$2" ]; then
	if [ $2 = "-bonus" ]; then
		objsfinal="$objsbonus"
	else
		buffer=$2
	fi
fi

$cc $flags -g -D BUFFER_SIZE=$buffer $objsfinal -o $name
