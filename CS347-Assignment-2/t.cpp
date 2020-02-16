#include<bits/stdc++.h>
#include<curses.h>

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

void removestrings(string &s) 
{ 
    int i=0;
    int n=s.length();
    while(i<n)
    {
    	if(s[i]=='\"')
    	{s[i]=' ';
    		i++;
    		while(i<n&&!(s[i]=='\"'&&s[i-1]!='\\'))
    		{
    			s[i++]=' ';
    		}
    		s[i]=' ';
    	}
    	i++;
    }
} 

vector <string> class_name;
vector <string> data_types={"int","float","vector","string","double","bool","long","short","char"};

string removespaces(string &s) 
{ 
    int i=0;
    int n=s.length();
    string final="";
    while(i<n)
    {

    	if(s[i]==' '&&i+1<n&&(s[i+1]=='{'||s[i+1]=='}'||s[i+1]==')'||s[i+1]=='('||s[i+1]==':'||s[i+1]==';'||s[i+1]==','||s[i+1]=='='))
    	{
    		i++;
    		continue;
    	}
    	if(s[i]==' '&&i+9<n&&s.substr(i+1,8)=="operator"&&!isalnum(s[i+9])&&s[i+9]!='_')
    		s[i]=':';
    	final+=s[i];
    	if(s[i]=='(')
    	{	smatch m;
    		bool flag=0;
    		int x=i;
    		while(s[i]!=')')
    			i++;
    		int y=i;
    		if(y-x<2){
    			final+="_";
    			continue;
    		}
    		
			for(int j=0;j<data_types.size();j++)
			{
			regex e{"[ (,]"+data_types[j]+"[ ]"};
			string test=s.substr(x,y-x+1);
			std::regex_search(test,m,e);
			if(m.size()>0){
				flag=1;
				break;
			}
			}

    		if(!flag)
    			final+="_";
    		
    		continue;
    	}
    	if((s[i]==';'||s[i]=='{'||s[i]=='}'||s[i]==':'||s[i]==';'||s[i]==','||s[i]=='('||s[i]==')'||s[i]=='=')&&i+1<n&&s[i+1]==' ')
    	{
    		i++;
    	}
    	i++;
    }
    return final;
} 

string removecharacters(string &s)
{
	string test="";
	int n=s.length();
	int i=0;
	string temp="";
	while(i<n)
	{
		test+=s[i];
		if(s[i]==')')
		{int j=i+1;
			while(j<n&&s[j]!=';'&&s[j]!='{'){
				temp+=s[j];
				j++;
			}
			if((j<n&&s[j]==';')||j==n){
				test+=temp;
				i=j;
			}
			else
				i=j;
			temp="";
		}
		else
			i++;
	}
	return test;
}

string remove_extra_comma(string &s)
{
	string test="";
	int n=s.length();
	int i=0;
	while(i<n)
	{
		
		if(s[i]==','&&i+1<n&&(s[i+1]==','||s[i+1]==';')){
			i++;
			continue;
		}
		test+=s[i];
		i++;
	}
	return test;
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

bool isliteral(char c)
{
	if(isalpha(c)||isdigit(c)||c=='_')
		return  1;
	return 0;
}

string optimize(string &s)
{
	//Remove Comments
	s=removeComments(s);
	//Remove Strings	
	removestrings(s);
	//Replace newline and tab with space
	for(int i=0;i<s.length();i++)
		if(s[i]=='\n'||s[i]=='\t')
			s[i]=' ';
	//Remove extra spaces
	removeSpaces(s);
	s+=' ';
	string xyz=s;
	s=";"+xyz;
	//Remove whitespaces before and after brackets and delimiters and content between ()
	s=removespaces(s);
	//Remove content between ) and { if not ';' occurs in between
	s=removecharacters(s);
	//Remove extra , before , or ;
	s=remove_extra_comma(s);
	return s;
}
void write_to_file(void);

ifstream fin;
ofstream fout;
string s=" ";
int n;
regex class_reg("[ {}:;](class)([ ])");
string object_prefix="[}{;:]";
string object_suffix="([ ])(((([a-zA-Z][a-zA-Z0-9_]*)(([=]([a-zA-Z][a-zA-Z0-9_]*))?(\\(\\))?))(\\([_]\\))?(,)?)+);";
regex operator_regex("[:](operator)([ ]?)(\\+=|-=|\\*=|/=|%=|\\^=|&=|\\|=|<<|>>|>>=|<<=|==|!=|<=|>=|<=>|&&|\\|\\||\\+\\+|--|\\,|->\\*|\\->|\\(\\s*\\)|\\[\\s*\\]|\\+|-|\\*|/|%|\\^|&|\\||~|!|=|<|>)\\([_]?\\)\\{");
string constructor_prefix="[{};:]";
string constructor_suffix="\\([_]?\\)\\{";

vector <string> object_defs;
vector <string> operator_defs;
vector <string> iclass_names;


int main()
{
	cout<<"Enter file name (In current directory): ";
	string file_name;
	cin>>file_name;
	cout<<endl;
	fin.open(file_name,ios::in);
	fout.open("out.txt",ios::out);
	string temp;
	while(getline(fin,temp)){
		int len=0;
		if(temp.length()>0&&temp[0]!='#'){	//Discard blanklines and macros
		s+=temp;
		s+="\n";
		}
	}
	s=optimize(s);
	cout<<s<<endl;
	n=s.length();
	cout<<"Number of Characters after optimization: "<<n<<endl;
	initscr();
	cbreak();
	clear();
	int maxrows=LINES;
	int maxcols=COLS;
	int cur=0;
	mvaddstr(7,maxcols/2-9,"CS347 ASSIGNMENT 2");
	double x=(double)n/100;
	int left=maxcols/2-51;
	for(int j=left+1;j<left+101;j++)
		mvaddch(10,j,'~');
	for(int j=left+1;j<left+101;j++)
		mvaddch(12,j,'~');
	mvaddch(11,left,'|');
	mvaddch(11,left+102,'|');
	refresh();
	double y=1;
	int count=0;
	while(cur<n-1)
	{
		while(s[cur]!=';'&&s[cur]!='{'&&s[cur]!='}'&&s[cur]!=':')
		cur++;
		int space_count=0;

		for(int end=cur+1;end<n;end++)
		{bool breakline=0;
		if(s[end]==' ')
			space_count++;
			if(space_count>1)
			{
				cur++;
				break;
			}
			//cout<<cur<<" "<<end<<" "<<s[cur]<<endl;
			//Match with inherited class and class from current character
			if(regex_match(s.begin()+cur,s.begin()+end+1,class_reg))
			{
				classdef+=1;
				string name="";
				cur=end+1;
				bool flag=0;
				while(isliteral(s[cur]))	//Storing class name int name var
					name.push_back(s[cur++]);
				while(whitespace(s[cur]))
					cur++;
				if(s[cur]==':'){
					iclassdef+=1;
					flag=1;
				}
				while(s[cur]!='{')			//Skiping until start of class
					cur++;
				class_name.push_back(name);	//Storing class name
				if(flag)
					iclass_names.push_back(name);
				breakline=1;
			}	
			
			//Match with operator overloaded function from current character
			else if(regex_match(s.begin()+cur,s.begin()+end+1,operator_regex))
			{
				overfuncdef+=1;
				cur++;
				string name="";
				while(s[cur]!='(')
					name.push_back(s[cur++]);
				while(s[cur]!='{')			//Skipping until start of function
					cur++;
				breakline=1;
				operator_defs.push_back(name);
			}
			else 
			{	bool flag=1;
				//Try to match with object declaration
				for(int i=0;i<class_name.size();i++)
				{
					regex op{object_prefix+class_name[i]+object_suffix};
					if(regex_match(s.begin()+cur,s.begin()+end+1,op))
					{
						od+=1;
						string name="";
						while(s[cur]!=' ')
							cur++;
						cur++;
						while(cur!=end)
						{name="";
							while(s[cur]!=','&&s[cur]!='('&&s[cur]!=';'&&s[cur]!='=')
								name.push_back(s[cur++]);
							while(cur<end&&s[cur]!=',')
								cur++;
							if(s[cur]==',')
								od+=1;
							if(cur<end)
								cur++;
							object_defs.push_back(class_name[i]+" "+name);
						}
						flag=0;
						breakline=1;
						break;
					}
				}
				if(flag)
				{
				//Try to match with constructor
				for(int i=0;i<class_name.size();i++)
				{
					regex op{constructor_prefix+class_name[i]+"::"+class_name[i]+constructor_suffix};
					regex op2{constructor_prefix+class_name[i]+constructor_suffix};
					if(regex_match(s.begin()+cur,s.begin()+end+1,op)||regex_match(s.begin()+cur,s.begin()+end+1,op2))
					{
						constructdef+=1;
						while(s[cur]!='{')			//Skipping until start of function
							cur++;
						flag=0;
						breakline=1;
						break;
					}
				}
				}
				
			}
			//Progress Bar
			if((double)cur>y*x)		
				{
					y++;
					mvaddch(11,left+1+count,'*');
					refresh();
					count++;
				}
			if(breakline){
				break;
			}
			if(end==n-1||s[end]==';'){
				cur++;
				break;
			}
		}
			
	}
	//Progress Bar
	while(count<100)
	{
		mvaddch(11,left+1+count,'*');
		refresh();
		count++;
	}
	
	write_to_file();
	string print="Class Definitions: "+to_string(classdef);
	mvaddstr(15,0,print.c_str());
	print="Inherited Class Definitions: "+to_string(iclassdef);
	mvaddstr(16,0,print.c_str());
	print="Constructor Definitions: "+to_string(constructdef);
	mvaddstr(17,0,print.c_str());
	print="Overloaded operator Definitions: "+to_string(overfuncdef);
	mvaddstr(18,0,print.c_str());
	print="Object Declarations: "+to_string(od);
	mvaddstr(19,0,print.c_str());
	print="Class Names: ";
	for(int i=0;i<class_name.size();i++){
		print+="'";
		print+=class_name[i];
		print+="' ";
	}
	mvaddstr(20,0,print.c_str());
	print="Inherited Class Names: ";
	for(int i=0;i<iclass_names.size();i++){
		print+="'";
		print+=iclass_names[i];
		print+="' ";
	}
	mvaddstr(21,0,print.c_str());
	print="Object Declarations: ";
	for(int i=0;i<object_defs.size();i++)
	{
		print+="'";
		print+=object_defs[i];
		print+="' ";
	}
	mvaddstr(22,0,print.c_str());
	print="Operator Overloaded definitions: ";
	for(int i=0;i<operator_defs.size();i++)
	{
		print+="'";
		print+=operator_defs[i];
		print+="' ";
	}
	mvaddstr(23,0,print.c_str());
	mvaddstr(maxrows-1, 0, "Press any key to quit");
	refresh();
	getch();
	endwin();

	fin.close();
	fout.close();
	
	return 0;
}

void write_to_file(void)
{
	fout<<"Class Definitions: "<<classdef<<endl;
	fout<<"Inherited Class Definitions: "<<iclassdef<<endl;
	fout<<"Constructor Definitions: "<<constructdef<<endl;
	fout<<"Overloaded operator Definitions: "<<overfuncdef<<endl;
	fout<<"Object Declarations: "<<od<<endl;
	fout<<"Class Names: ";
	for(int i=0;i<class_name.size();i++)
		fout<<"'"<<class_name[i]<<"' ";
	fout<<endl;
	fout<<"Inherited Class Names: ";
	for(int i=0;i<iclass_names.size();i++)
		fout<<"'"<<iclass_names[i]<<"' ";
	fout<<endl;
	fout<<"Object Declarations: ";
	for(int i=0;i<object_defs.size();i++)
		fout<<"'"<<object_defs[i]<<"' ";
	fout<<endl;
	fout<<"Operator Overloaded definitions: ";
	for(int i=0;i<operator_defs.size();i++)
		fout<<"'"<<operator_defs[i]<<"' ";
	fout<<endl;
}
