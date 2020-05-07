#include "codegenHelpers.h"

/*Added by SSR*/



void merge(vector<int> *&receiver, vector<int> *&donor) {
    if(donor==NULL || receiver == NULL){
        
        return;
    }
    for(int i:(*donor)){
        receiver->push_back(i);
    }
    donor->clear();
    return;
}

void mergeSwitch(vector<pair<string,int>> *&receiver,vector<pair<string,int>> *&donor) {
    if(donor==NULL || receiver == NULL){
        
        return;
    }
    for(auto i:(*donor)){
        receiver->push_back(i);
    }
    donor->clear();
    return;
}

/*Added by Sid and Shubham */

string registerSet::getRegister() {
    string reg = "";
    if (tempRegister.size()==0) {
        cout << BOLD( FRED ("FATAL ERROR : Exceeded maximum temporary Int registers") ) << endl;
        exit(1);
        return reg;
    }
    reg += "T";
    int x = tempRegister[tempRegister.size()-1];
    reg += to_string(x);
    tempRegister.pop_back();
    return reg;
}


string registerSet::getFloatRegister() {
    string reg = "";
    if (floatRegister.size()==0) {
        cout << BOLD (FRED ("FATAL ERROR : Exceeded maximum temporary Float registers") ) << endl;
        exit(1);
        return reg;
    }
    reg += "F";
    int x = floatRegister[floatRegister.size()-1];
    reg += to_string(x);
    floatRegister.pop_back();
    return reg;
}



void registerSet::freeRegister(string s){
    if(s[0]=='F'){
        s[0] = '0';
        int x = stoi(s);
        for(auto it : floatRegister){
            if(it==x){
                
                return;
            }
        }
        
        floatRegister.push_back(x);
    } else if(s[0] == 'T'){
        s[0] = '0';
        int x = stoi(s);
        for(auto it:tempRegister){
            if(it==x){
                
                return;
            }
        }
        
        tempRegister.push_back(x);
    } else {
        cout << "Not a Temp Variable : " << s << endl;
    }
}
/*Added by SSR*/

void backpatch(vector<int> *&lineNumbers, int labelNumber, vector<string> &functionInstruction){
    if(lineNumbers == NULL){
        cout << "Written Line Number for: "<<labelNumber<<" is NULL"<<endl;
        return;
    }
    string statement;
    for(int it : (*lineNumbers)){
        
    }
    lineNumbers->clear();
}



void gen(vector<string> &functionInstruction, string instruction, int &nextQuad){
    functionInstruction.push_back(instruction);
    nextQuad++;
    
    return;
}

