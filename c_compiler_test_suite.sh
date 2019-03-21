#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

make compiler

if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}."
    exit
fi



input_dir="test_deliverable/test_cases"
working="working"

mkdir -p ${working}


for i in ${input_dir}/*.c ; do
    j=${i##*/}
    base=${j%.c}
    #base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+[^_driver])[.]c|\1|g")
    if [ "${base: -7}" = "_driver" ]; then
        continue;
    fi
    $compiler -S $input_dir/$base.c -o $working/$base.s #&> /dev/NULL

    mips-linux-gnu-gcc -mfp32 -o $working/$base.o -c $working/$base.s #&> /dev/NULL

    base_drivers="${base}_driver"

    mips-linux-gnu-gcc -mfp32 -static -o $working/$base $working/$base.o $input_dir/$base_drivers.c #&> /dev/NULL

    qemu-mips $working/$base #&> /dev/NULL

    GOT_OUT=$?
    if [[ $GOT_OUT -ne 0 ]] ; then
        echo -e "${wht}$base ${red}[FAIL] ${wht}Expected 0 got $GOT_OUT \n"

    else
        echo -e "${wht}$base [PASS] \n"

    fi

done

input_dir="test_deliverable/other_tests"

for i in ${input_dir}/*.c ; do
    j=${i##*/}
    base=${j%.c}
    #base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+[^_driver])[.]c|\1|g")
    if [ "${base: -7}" = "_driver" ]; then
        continue;
    fi
    $compiler -S $input_dir/$base.c -o $working/$base.s #&> /dev/NULL

    mips-linux-gnu-gcc -mfp32 -o $working/$base.o -c $working/$base.s #&> /dev/NULL

    base_drivers="${base}_driver"

    mips-linux-gnu-gcc -mfp32 -static -o $working/$base $working/$base.o $input_dir/$base_drivers.c #&> /dev/NULL

    qemu-mips $working/$base #&> /dev/NULL

    GOT_OUT=$?
    if [[ $GOT_OUT -ne 0 ]] ; then
        echo -e "${wht}$base ${red}[FAIL] ${wht}Expected 0 got $GOT_OUT \n"

    else
        echo -e "${wht}$base [PASS] \n"

    fi

done
