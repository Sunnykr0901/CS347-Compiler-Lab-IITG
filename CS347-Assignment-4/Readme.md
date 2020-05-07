<h2> How to Run ? </h2>
<h3>Compile</h3>
<h4>$ make clean <br/></h4>
<h4>$ make </h4>
*executable file created as 'exe'*

![alt text][logo]

[logo]: https://i.ibb.co/zZy6Tk9/3.png "Example"

<h3>Execute</h3>

$ ./exe <input/test.txt

*where test.txt contains the Queries to run.*

<h3>Query Format should be as:</h3>

- SELECT <condition> (Table_Name)
- PROJECT <attribute_list> (Table_Name)
- <Table_Name_1 > CARTESIAN_PRODUCT < Table_Name_2 >
- <Table_Name_1 > EQUI_JOIN <condition> < Table_Name_2 >
  
  Example:<br/>
 ![alt text][logo2]

[logo2]: https://i.ibb.co/THr0nz0/4.png "Example"

where '\n'(newline)  is delimiter<br/>
**Each query (Including last) should be followed by '\n'**

csv files should be in directory named 'input' in folder in which all the files are present.<br/>
First Row of csv contain name of the Columns and  second row should have datatype of coressponding Column 

