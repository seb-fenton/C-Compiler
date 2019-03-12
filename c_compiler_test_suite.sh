#!/bin/bash

make compiler -B 

input_dir="test_deliverable/test_cases"

working="bin/compiler"
mkdir -p ${working}


for i in ${input_dir}/*.c ; do

    base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");

    # Compile the reference C version
    gcc $i -std=c90 -ansi -o $working/$base
    
    # Run the reference C version
    $working/$base
    REF_C_OUT=$?
        
    # Compile to assembly using 
    $compiler -S $i -o ${working}/$base-got.s


	mips-linux-gnu-gcc -march=mips1 -mfp32 -w -O0 -static  ${working}/$base-got.s -o ${working}/$base-got	

    # Run the tested compiler assembly version
    qemu-mips ${working}/$base-got
    GOT_P_OUT=$?
    
    if [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo -e "${wht}$base.c ${red}[FAIL] ${wht}Expected ${REF_C_OUT} got ${GOT_P_OUT}"

    else
        echo -e "${wht}$base.c ${grn}[PASS]""${red}"

	rm tmp/compiler/$base-got.s
	rm tmp/compiler/$base
    fi

done