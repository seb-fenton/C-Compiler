#!/bin/bash

make compiler -B 
COMPILER="bin/c_compiler"

workingin="test/test_deiliverable/test_cases"
workingout="test/test_deiliverable/output"

mkdir -p $workingout


for DRIVER in $workingin/*_driver.c ; do
    NAME=$(basename $DRIVER _driver.c)
    TESTCODE=$workingin/$NAME.c
        
    # Generate assembly for driver
    mips-linux-gnu-gcc -S -w -march=mips1 -mfp32 -O0 $DRIVER -o $workingout/${NAME}_driver.s
    
    # Generate assembly for slave
    $COMPILER -S $workingin/${NAME}.c -o $workingout/${NAME}.s
    
    # Generate GOT_EXIT_CODE
    mips-linux-gnu-gcc -w -static $workingout/${NAME}_driver.s $workingout/${NAME}.s -o $workingout/${NAME}_result
    qemu-mips $workingout/${NAME}_result
    GOT_EXIT_CODE=$?
    
    # Generate EXP_EXIT_CODE
    mips-linux-gnu-gcc -w -static -march=mips1 -mfp32 -O0 $workingin/${NAME}.c $workingin/${NAME}_driver.c -o $workingout/${NAME}_gcc_result
    qemu-mips $workingout/${NAME}_gcc_result
    EXP_EXIT_CODE=$?
    
    if [[ $GOT_EXIT_CODE -ne $EXP_EXIT_CODE ]]; then
        echo -e $NAME.c "[FAIL]" "Expected" $EXP_EXIT_CODE ", got" $GOT_EXIT_CODE
    else
   	    echo -e $NAME.c "[PASS]"
    fi
    
    
done

make clean
rm -f $workingout