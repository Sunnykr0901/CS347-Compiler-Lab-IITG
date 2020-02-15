#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;
int od=0,classdef=0,constructdef=0,iclassdef=0,overfuncdef=0;

vector <string> class_names;

ifstream fin;
ofstream fout;

bool whitespace(char c)
{
	if(c==' '||c=='\t'||c=='\n'||c=='	')
		return  1;
	return 0;
}

bool ewhitespace(char c)
{
	if(c==' '||c=='\t'||c=='\n'||c=='	'||c==';')
		return  1;
	return 0;
}

void skip(int &i,int &n,string &s,int mode)
{
	if(mode==0){	//Skip whitespaces
	while(i<n&&whitespace(s[i]))
		i++;
	while(i==n)
	{
		getline(fin,s);
		n=s.length();
		i=0;
		if(n==0)
			return;
		while(i<n&&whitespace(s[i]))
			i++;
	}
	}
	else{	//Skip whitespaces and ';'
	while(i<n&&ewhitespace(s[i]))
		i++;
	while(i==n)
	{
		getline(fin,s);
		n=s.length();
		i=0;
		if(n==0)
			return;
		while(i<n&&ewhitespace(s[i]))
			i++;
	}
	}
	
}


bool getnext(int &i,int &n,string &s,int mode,string &word)
{word.clear();
	if(mode==0)	//Skip whitespaces and get next word
	{
		skip(i,n,s,mode);
		while(i<n&&!whitespace(s[i]))
			word.push_back(s[i++]);
	}
	else	//Skip whitespaces and ';' and get next word
	{
		skip(i,n,s,mode);
		while(i<n&&!ewhitespace(s[i]))
			word.push_back(s[i++]);
	}
	if(word.length()>0)
		return 1;
	else
		return 0;
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
	string word;
	getline(fin,s);
	n=s.length();
	bool breakline=0;
	while(getnext(i,n,s,1,word)){

		breakline=0;
		int m=word.length();
		int j=0;
		if(word=="class"){	//Class definition
			classfunc();
			continue;
		}
		for(int k=0;k<class_names.size();k++)	
			if(class_names[k]==word)
			{
						
			}

		while(j<m)
		{

		switch(word[j])
		{
			case '/': //May be start of a comment
					if(j+1<m&&word[j+1]=='/')//Its a single line comment
					{
					getline(fin,s);
					i=0;
					n=s.length();
					breakline=1;
					break;	
					}	
						
					else if(j+1<m&&word[j+1]=='*')	//Its a multi line comment
					{
						j+=2;
						while(j<m&&word[j]!='*'&&j+1<m&&word[j+1]!='/')
							j++;
						if(j<m&&word[j]=='*'&&j+1<m&&word[j+1]=='/'){
							j+=1;
							break;
						}
						while(getnext(i,n,s,1,word))
						{
							j=0;
							m=word.length();
							while(j<m&&word[j]!='*'&&j+1<m&&word[j+1]!='/')
							j++;
							if(j<m&&word[j]=='*'&&j+1<m&&word[j+1]=='/'){
								j+=1;
								break;
						}

						}

					}
			case '\\': if(quote)
						j++;
						break;
			case '"': j++;
						while(j<m&&word[j]!='"'&&!(word[j]=='"'&&j>0&&word[j-1]=='\\'))
							j++;
						if(j<m&&word[j]=='"'){
							break;
						}
						while(getnext(i,n,s,1,word))
						{
							j=0;
							m=word.length();
							while(j<m&&word[j]!='"'&&!(word[j]=='"'&&j>0&&word[j-1]=='\\'))
								j++;
							if(j<m&&word[j]=='"'){
							break;
						}
						}

			default:
					break;

		}
		j++;
		if(breakline)
			break;
	}
		
	}
	}
	cout<<classdef<<" "<<iclassdef<<endl;
	fin.close();
	fout.close();

	return 0;
}