#!/bin/bash

filename=${1%.*}
driver=${2%.*}

bin/c_compiler -S $filename.c -o $filename.s

mips-linux-gnu-gcc -mfp32 -o $filename.o -c $filename.s

mips-linux-gnu-gcc -mfp32 -static -o $filename $filename.o $driver.c

qemu-mips $filename
echo $?