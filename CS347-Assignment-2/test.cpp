#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;
int od=0,classdef=0,constructdef=0,iclassdef=0,overfuncdef=0;

ifstream fin;
ofstream fout;

bool whitespace(char c)
{
	if(c==' '||c=='\t'||c=='\n'||c=='	')
		return  1;
	return 0;
}

void skip(int &i,int &n,string &s)
{
	while(i<n&&whitespace(s[i])){
		//cout<<"skipped: "<<i<<endl;
		i++;
	}
	while(i==n)
	{
		getline(fin,s);
		n=s.length();
		i=0;
		while(i<n&&whitespace(s[i])){
		//cout<<"skipped: "<<i<<endl;
		i++;
	}
	}
}


int main()
{
	
	fin.open("input.txt",ios::in);
	fout.open("out.txt",ios::out);
	string s;
	bool outside=1;
	char c;
	int i=0;
	int n;
	bool quote=0;
	while(getline(fin,s)&&s.length()>0){
		n=s.length();
		i=0;
		//cout<<s<<endl;
		bool breakline=0;
	while(i<n)
	{//cout<<i<<" "<<s[i]<<endl;
		switch(s[i])
		{
			case '/': //May be start of a comment
					if(i+1<n&&s[i+1]=='/')//Its a single line comment
					{
					breakline=1;
					break;	
					}	
						
					else if(i+1<n&&s[i+1]=='*')	//Its a multi line comment
					{
						i+=2;
						while(i<n&&s[i]!='*'&&i+1<n&&s[i+1]!='/')
							i++;
						while(i>=n-1)
						{
							getline(fin,s);
							n=s.length();
							i=0;
							while(i<n&&s[i]!='*'&&i+1<n&&s[i+1]!='/')
							i++;
						}
						i+=1;

					}
					break;
			case '\\': if(quote)
						i++;
						break;
			case '"': if(!quote)
						quote=1;
						else
							quote=0;
						break;


			case 'c': if(!quote&&i+5<n&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='s'&&whitespace(s[i+5])&&(i==0||whitespace(s[i-1])))
						{//cout<<"Came here\n";
							i+=5;
							//cout<<"Came here2\n";
							skip(i,n,s);
							//cout<<"Came here3\n";
							while(i<n&&!whitespace(s[i++]));
							i--;
							//cout<<"Came here4\n";
							skip(i,n,s);
							if(s[i]=='{')	//Normal class definition
							{
								classdef++;
							}
							else if(s[i]==':')	//Inheroted class defintion
							{
								iclassdef++;
								classdef++;
							}
							bool flag=0;
							//cout<<"Came here5\n";
							while(!(flag&&s[i]==';'))
							{
								if(s[i]=='}'){
									flag=1;
									i++;
								}
								else if(!whitespace(s[i])){
									flag=0;
									i++;
								}
								else
									skip(i,n,s);
							}



						}
					break;
			default:
					break;

		}
		i++;
		if(breakline)
			break;
	}
	}
	cout<<classdef<<" "<<iclassdef<<endl;
	fin.close();
	fout.close();

	return 0;
}