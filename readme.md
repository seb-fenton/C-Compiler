2018/2019 Compilers Coursework
==============================

There is a single assessed code deliverable. This deliverable contains three components:

- [*Test suite*]: A bash script that runs the basic C funcionality tests in test_deliverable/test_cases.

- [*C-translator*]: This compiler is able to translate a sub-set of C into equivalent Python. 

- [*C-compiler*]: This is a compiler from C to MIPS assembly.
  
In all cases, the source language is pre-processed C90. The target environment is Ubuntu 16.04.

C-compiler features
===================
Here is a list of basic features that the compiler handles:

* a file containing just a single function with no arguments
* variables of `int` type
* local variables
* arithmetic and logical expressions
* if-then-else statements
* while loops

And here is a list of the intermediate features that the compiler also implements:

* files containing multiple functions that call each other
* functions that take up to four parameters
* for loops
* arrays declared globally (i.e. outside of any function in your file)
* arrays declared locally (i.e. inside a function)
* reading and writing elements of an array
* recursive function calls
* the `enum` keyword
* `switch` statements
* the `break` and `continue` keywords

Using the test suite
====================

To run the test suite for the compiler, simply type ./c_compiler_test_suite (and make sure it has permission enabled using chmod u+x). To extend the test suite, add a pair of .c and _driver.c files to the test_deliverable/test_cases folder.