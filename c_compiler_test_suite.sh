#!/bin/bash

make compiler -B 

input_dir="test_deliverable/test_cases"
working="bin/working"

mkdir -p ${working}


for i in ${input_dir}/*.c ; do

    base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+[^_driver])[.]c|\1|g")

    base_drivers=$(echo $i | sed -E -e "s|${input_dir}/([^.]+[_driver])[.]c|\1|g")

    bin/c_compiler -S $input_dir/$base.c -o $working/$base.s

    mips-linux-gnu-gcc -mfp32 -o $working/$base.o -c $working/$base.s

    mips-linux-gnu-gcc -mfp32 -static -o $working/$base $working/$base.o $working/$base_drivers.c

    qemu-mips test_program

    GOT_OUT=$?

    if [[ $GOT_OUT -ne 0 ]] ; then
        echo -e "${wht}$base.c ${red}[FAIL] ${wht}Expected 0 got $GOT_OUT"

    else
        echo -e "${wht}$base.c [PASS]"

    rm bin/working/*
    fi

done

make clean