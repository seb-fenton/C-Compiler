#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building parser"
make parser -B
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""
mkdir -p output

echo "========================================="

PASSED=0
CHECKED=0

for i in testfiles/in/*.txt; do
    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    BASENAME=$(basename $i .txt);
    cat $i | ./parser > testfiles/out/$BASENAME.stdout.txt  2> testfiles/out/$BASENAME.stderr.txt

    diff <(cat testfiles/ref/$BASENAME.stdout.txt) <(cat testfiles/out/$BASENAME.stdout.txt) > testfiles/out/$BASENAME.diff.txt
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