$ make clean
$ make

executable file created as 'exe'

execute the file as

$ ./exe <input/test.txt

where test.txt contains the Queries to run.

Query Format should be as:

- SELECT <condition> (Table_Name)
- PROJECT <attribute_list> (Table_Name)
- <Table_Name_1 > CARTESIAN_PRODUCT < Table_Name_2 >
- <Table_Name_1 > EQUI_JOIN <condition> < Table_Name_2 >

where '\n'(newline)  is delimiter

csv files should be in directory named 'input' in folder in which all the files are present.
First Row of csv contain name of the Columns and  second row should have datatype of coressponding Column 

