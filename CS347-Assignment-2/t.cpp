#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;
int od=0,classdef=0,constructdef=0,iclassdef=0,overfuncdef=0;

string removeComments(string prgm) 
{ 
    int n = prgm.length(); 
    string res; 
  
    // Flags to indicate that single line and multpile line comments 
    // have started or not. 
    bool s_cmt = false; 
    bool m_cmt = false; 
  
  
    // Traverse the given program 
    for (int i=0; i<n; i++) 
    { 
        // If single line comment flag is on, then check for end of it 
        if (s_cmt == true && prgm[i] == '\n') 
            s_cmt = false; 
  
        // If multiple line comment is on, then check for end of it 
        else if  (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/') 
            m_cmt = false,  i++; 
  
        // If this character is in a comment, ignore it 
        else if (s_cmt || m_cmt) 
            continue; 
  
        // Check for beginning of comments and set the approproate flags 
        else if (prgm[i] == '/' && prgm[i+1] == '/') 
            s_cmt = true, i++; 
        else if (prgm[i] == '/' && prgm[i+1] == '*') 
            m_cmt = true,  i++; 
  
        // If current character is a non-comment character, append it to res 
        else  res += prgm[i]; 
    } 
    return res; 
} 

void removeSpaces(string &str) 
{ 
    // n is length of the original string 
    int n = str.length(); 
  
    // i points to next position to be filled in 
    // output string/ j points to next character 
    // in the original string 
    int i = 0, j = -1; 
  
    // flag that sets to true is space is found 
    bool spaceFound = false; 
  
    // Handles leading spaces 
    while (++j < n && str[j] == ' '); 
  
    // read all characters of original string 
    while (j < n) 
    { 
        // if current characters is non-space 
        if (str[j] != ' ') 
        { 
            // remove preceding spaces before dot, 
            // comma & question mark 
            if ((str[j] == '.' || str[j] == ',' || 
                 str[j] == '?') && i - 1 >= 0 && 
                 str[i - 1] == ' ') 
                str[i - 1] = str[j++]; 
  
            else
                // copy current character at index i 
                // and increment both i and j 
                str[i++] = str[j++]; 
  
            // set space flag to false when any 
            // non-space character is found 
            spaceFound = false; 
        } 
        // if current character is a space 
        else if (str[j++] == ' ') 
        { 
            // If space is encountered for the first 
            // time after a word, put one space in the 
            // output and set space flag to true 
            if (!spaceFound) 
            { 
                str[i++] = ' '; 
                spaceFound = true; 
            } 
        } 
    } 
  
    // Remove trailing spaces 
    if (i <= 1) 
        str.erase(str.begin() + i, str.end()); 
    else
        str.erase(str.begin() + i - 1, str.end()); 
} 

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

bool isliteral(char c)
{
	if(isalpha(c)||isdigit(c)||c=='_')
		return  1;
	return 0;
}

vector <string> class_name;

ifstream fin;
ofstream fout;
string s=" ";
int n;
regex class_reg("[ ;](class)([ ])([a-zA-Z][a-zA-Z0-9_]*)([ ]?)\\{((.)*)\\}([ ]?);");
regex iclass_reg("[ ;](class)([ ])([a-zA-Z][a-zA-Z0-9_]*)([ ]?):([ ]?)([a-z]+)([ ])([a-zA-Z][a-zA-Z0-9_]*)([ ]?)\\{((.)*)\\}([ ]?);");
regex string_reg("\"((.)*)\"");
string object_prefix="[ ;:]([ ]?)";
string object_suffix="([ ])([a-zA-Z][a-zA-Z0-9_]*)([ ]?);";
regex operator_regex("(operator)([ ]?)(\\+=|-=|\\*=|/=|%=|\\^=|&=|\\|=|<<|>>|>>=|<<=|==|!=|<=|>=|<=>|&&|\\|\\||\\+\\+|--|\\,|->\\*|\\->|\\(\\s*\\)|\\[\\s*\\]|\\+|-|\\*|/|%|\\^|&|\\||~|!|=|<|>)([ ]?)\\{((.)*)\\}");
string constructor_prefix="[ ;:]([ ]?)";
string constructor_suffix="([ ]?)\\(((.)*)\\)([ ]?)\\{((.)*)\\}";

int main()
{
	
	fin.open("input.txt",ios::in);
	fout.open("out.txt",ios::out);
	string temp;
	while(getline(fin,temp)&&temp.length()>0){
		s+=temp;
		s+="\n";
	}
	s=removeComments(s);
	for(int i=0;i<s.length();i++)
		if(s[i]=='\n'||s[i]=='\t')
			s[i]=' ';
	removeSpaces(s);
	s+=' ';
	string xyz=s;
	s=" "+xyz;
	cout<<s<<endl;
	n=s.length();
	int cur=0;
	double x=(double)n/100;
	for(int i=0;i<101;i++)
		cout<<"~";
	cout<<"\n|";
	double y=1;
	int count=0;
	while(cur<n)
	{
		for(int end=cur;end<n;end++)
		{bool breakout=1;
			//cout<<cur<<" "<<end<<endl;
			//Match with string from current character
			if(regex_match(s.begin()+cur,s.begin()+end+1,string_reg)&&s[end-1]!='\\')
				cur=end+1;
			//Match with inherited class and class from current character
			else if(regex_match(s.begin()+cur,s.begin()+end+1,iclass_reg)||regex_match(s.begin()+cur,s.begin()+end+1,class_reg))
			{//cout<<"came here -1\n";
				
				if(regex_match(s.begin()+cur,s.begin()+end+1,iclass_reg))
					iclassdef+=1;
				classdef+=1;
				string name="";
				while(whitespace(s[cur]))	//Skip Initial whitespaces
					cur++;
				while(isalpha(s[cur]))		//Skip 'class' keyword
					cur++;
				while(whitespace(s[cur]))	//Skip whitespaces before class name
					cur++;
				while(isliteral(s[cur]))	//Storing class name int name var
					name.push_back(s[cur++]);
				while(s[cur]!='{')			//Skiping until start of class
					cur++;
				cur++;
				class_name.push_back(name);	//Storing class name
				//cout<<"came here 0\n";
			}		
			//Match with operator overloaded function from current character
			else if(regex_match(s.begin()+cur,s.begin()+end+1,operator_regex))
			{//cout<<"came here overload 1\n";
				overfuncdef+=1;
				while(s[cur]!='{')			//Skipping until start of function
					cur++;
				cur++;
				//cout<<"came here overload 2\n";
			}
			else 
			{	bool flag=1;
				//cout<<"came here 1\n";
				//Try to match with object declaration
				for(int i=0;i<class_name.size();i++)
				{
					regex op{object_prefix+class_name[i]+object_suffix};
					if(regex_match(s.begin()+cur,s.begin()+end+1,op))
					{
						od+=1;
						cur=end+1;
						flag=0;
						break;
					}
				}
				if(flag)
				{
					//cout<<"came here 2\n";
				//Try to match with constructor
				for(int i=0;i<class_name.size();i++)
				{
					regex op{constructor_prefix+class_name[i]+"([ ]*)::([ ]*)"+class_name[i]+constructor_suffix};
					regex op2{constructor_prefix+class_name[i]+constructor_suffix};
					if(regex_match(s.begin()+cur,s.begin()+end+1,op)||regex_match(s.begin()+cur,s.begin()+end+1,op2))
					{
						constructdef+=1;
						while(s[cur]!='{')			//Skipping until start of function
							cur++;
						cur++;
						flag=0;
						break;
					}
				}
				}
				//cout<<"came here 3\n";
				if(flag)
					breakout=0;
			}


			if(breakout){
				if((double)cur>y*x)
				{//cout<<y*x<<endl;
					y++;
					cout<<"*"<<flush;
					count++;
				}
				break;
			}
			if(end==n-1)
				cur++;	
			if((double)cur>y*x)
				{//cout<<y*x<<endl;
					y++;
					cout<<"*"<<flush;
					count++;
				}
		}
			
	}
	while(count<100)
	{
		cout<<"*";
		count++;
	}
	cout<<"|\n";
	for(int i=0;i<101;i++)
		cout<<"~";
	cout<<endl;

	cout<<"Object Declarations: "<<od<<endl;
	cout<<"Class Definitions: "<<classdef<<endl;
	cout<<"Inherited Class Definitions: "<<iclassdef<<endl;
	cout<<"Constructor Definitions: "<<constructdef<<endl;
	cout<<"Overloaded operator Definitions: "<<overfuncdef<<endl;
	
	return 0;
}
