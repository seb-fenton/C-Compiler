#!/bin/bash

mkdir -p bin

make compiler -B

input_dir="debugging/translator/tests/in"

working="bin/working"
mkdir -p ${working}

for i in ${input_dir}/*.c ; do
    base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
    
    # Compile the reference C version
    gcc $i -o $working/$base
    
    # Run the reference C version
    $working/$base
    REF_C_OUT=$?
      
    # Create the DUT python version by invoking the compiler with translation flags
    touch ${working}/$base.py
    bin/c_compiler --translate $i -o ${working}/$base.py
        
    # Run the DUT python version
    python ${working}/$base.py
    GOT_P_OUT=$?
    
    if [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo "$base, Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
    else
        echo "$base, Pass"
    fi
done
