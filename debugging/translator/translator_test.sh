#!/bin/bash

if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    # This works on a GNU version of sed. I think this
    # will work in OSX as well, but don't have a machine
    # on which to test that. From reading the OSX docs,
    # it looks compatible.
    # The code \x0D is the ASCII code of carriage-return,
    # so it the regex should delete any CRs at the end of
    # a line (or anywhere in a line)
    DOS2UNIX="sed -e s/\x0D//g -"
    # Tested for combinations of:
    # - Ubuntu
    # - Cygwin
    # and inputs formats:
    # - LF
    # - CRLF
fi

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building translator"
cd ../../
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
    ../../bin/c_compiler --translate ${i} -o tests/out/$BASENAME.py
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

cd ../../
make clean