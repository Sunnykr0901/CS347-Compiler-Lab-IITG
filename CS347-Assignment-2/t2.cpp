#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;
int od=0,classdef=0,constructdef=0,iclassdef=0,overfuncdef=0;

vector <string> class_name;

ifstream fin;
ofstream fout;
string s="\n";
int n;

regex class_reg("[ \\t\\n;](class)([ \\t\\n]+)([a-zA-Z][a-zA-Z0-9_]*)([ \\t\\n]*)\\{((.|\\n)*)\\}([ \\t\\n]*);");

int main()
{
	
	fin.open("input.txt",ios::in);
	fout.open("out.txt",ios::out);
	string temp;
	while(getline(fin,temp)){
		s+=temp;
		s+="\n";
	}
	cout<<s;
	n=s.length();
	int cur=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{//cout<<i<<" "<<j<<endl;
			if(regex_match(s.begin()+i,s.begin()+j+1,class_reg))
			{
				cout<<"MATCH: "<<i<<" "<<j<<endl;
				for(int k=i;k<=j;k++)
					cout<<s[k];
				cout<<endl;
			}	
		}
	}
	cout<<"Object Declarations: "<<od<<endl;
	cout<<"Class Definitions: "<<classdef<<endl;
	cout<<"Inherited Class Definitions: "<<iclassdef<<endl;
	cout<<"Constructor Definitions: "<<constructdef<<endl;
	cout<<"Overloaded operator Definitions: "<<overfuncdef<<endl;
	
	return 0;
}
