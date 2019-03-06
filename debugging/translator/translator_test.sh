#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building translator"
cd ../../full_compiler 
make compiler -B
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""
cd ../debugging/translator
mkdir -p output

echo "========================================="

PASSED=0
CHECKED=0

for i in tests/in/*.c; do
    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    BASENAME=$(basename $i .c);
    touch tests/out/$BASENAME.py
    ../../full_compiler/bin/c_compiler --translate ${i} -o tests/out/$BASENAME.py
    diff <(cat tests/ref/$BASENAME.py) <(cat tests/out/$BASENAME.py) > tests/diff/$BASENAME.diff.py
    if [[ "$?" -ne "0" ]]; then
        echo -e "\nERROR"
    else
        PASSED=$(( ${PASSED}+1 ));
    fi
    CHECKED=$(( ${CHECKED}+1 ));
done


echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""

cd ../../full_compiler
make clean