#!/bin/sh

rm output/intermediate.txt 
rm output/symtab.txt
rm ../secondPass/mips.s 
sleep 1

./Parser < "input/"$1
cd ../secondPass
./Intermediate < ../firstPass/output/intermediate.txt
cd ../firstPass