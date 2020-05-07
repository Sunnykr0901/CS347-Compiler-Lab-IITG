# A Simple C Compiler

We have implemented a simple Compiler for a subset of the **C language** consisting of the following operations:
1. Variable declarations, for int and float data types.
2. Arithmetic, logical and relational expressions (with suitable short-circuit evaluation,
wherever applicable).
3. Function calls and function definitions.
4. Conditional expressions: if-else and switch-case statements.
5. Loops: for and while. 

# Getting Started
The compilation is done in two passes: 
>The first pass takes a C program (as .c format file) as input and produces the 3 address code in Quadruple format as output. 
The second pass takes the generated quadruple format Intermediate code as input and produces the target MIPS code as output, runnable on the SPIM simulator.

## Prerequisites

The following software must be pre-installed on your system to run the compiler:
###  flex
> sudo apt install flex
### bison
> sudo apt install bison
### SPIM MIPS Simulator
This can be installed here: http://spimsimulator.sourceforge.net/

## Deployment

### Build the compiler
Run make on both the **First Pass** and **Second Pass** directories.
### Execute the compiler
Run the **execute.sh** script in the **First Pass** directory, passing as argument the name of any of the input **C** files in the **input** directory.
The target MIPS code is outputted to the **mips.s** file in the **Second Pass directory**. 
### Run the Simulator
Load the **mips.s** file to the SPIM MIPS Simulator. Run the file, and enter input and view output on the console.
