# Python Interpreter (Partial)

Description
This is a partial interpreter for python 2.7.2, written by Claire DeMars, 
based on a Flex and Bison parser auto-generated from the python specs 
and building on code for a basic abstract syntax tree (AST) written by professor Brian Malloy, 
for the course 8270 - Translation of Programming Languages at Clemson University, Fall 2017

Commands
  Compile: make
  Run: run
  Test:
    python test.py // runs the tests in ./cases and compares the result to Python's output
  
Dependencies 
  Flex
  Bison
  C++11 compiler (g++ or clang++)
  Python (for the test suite, which compares the program's output to Python's)
 
Supported Behavior
  Integer and float values and variables
  Printing 
  Assignment
  These Operations: x + y, x − y, x ∗ y, x/y, x//y, x%y, x∗∗e, 
    x+ = y, x− = y, x∗ = y, x/ = y, x// = y, x% = y
  These Expressions:
     (x), −x, +x
  Functions (without parameters)
  Return values
  Static scoping (with the difference that this program processes the function line-by-line,
      instead of predeclaring all local variables like Python)
  if/else (not elif)
  These Relational Operators: 
     <, <=, ==, >, >=, != 




  
  

  
