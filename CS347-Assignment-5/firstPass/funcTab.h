#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;


#define FBLU(x) KBLU x RST

#define FYEL(x) KYEL x RST
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define FMAG(x) KMAG x RST
#define KCYN  "\x1B[36m"
#define FWHT(x) KWHT x RST
#define FRED(x) KRED x RST
#define RST  "\x1B[0m"

#define FCYN(x) KCYN x RST
#define BOLD(x) "\x1B[1m" x RST
#define KBLU  "\x1B[34m"
#define UNDL(x) "\x1B[4m" x RST
#define KWHT  "\x1B[37m"
#define FGRN(x) KGRN x RST
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"

enum varType {SIMPLE, ARRAY};

enum Tag{PARAMAETER, VARIABLE};
enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};

struct expression{
    string* offsetRegName;
    string* registerName;
    eletype type;
};

struct stmt {
    vector<int> *continueList;
    vector<int> *nextList;
    vector<int> *breakList;
};

struct whileexp {
    int begin;
    vector<int> *falseList;
};

struct shortcircuit{
    string* registerName;
    eletype type;
    vector<int>* jumpList;
};

struct condition2temp{
    vector<int> *temp;
};

struct switchcaser{
    vector<int> *continueList;
    vector<int> *breakList;
    vector<int> *nextList;
    vector<pair<string,int>> *casepair;
};

struct switchtemp{
    vector<pair<string,int>> *casepair;
};

struct typeRecord {
    int varOffset;
    vector<int> dimlist; 
    eletype eleType;
    int maxDimlistOffset;
    bool isValid;
    string name;
    Tag tag;
    varType type;
    int scope;
}; 

struct funcEntry {
        int numOfParam;
    vector <typeRecord*> variableList;
    vector <typeRecord*> parameterList;
    int functionOffset;
string name;
    eletype returnType;
}; 

int eletypeIntMapper(eletype a);
void deleteVariableList(funcEntry* activeFuncPtr, int scope);

int TagMapper(Tag a);
void printList(vector<funcEntry*> &funcEntryRecord);
bool arithmeticCompatible(eletype type1, eletype type2);
void printFunction(funcEntry* &activeFuncPtr);
void VariableSearch(string name, funcEntry* activeFuncPtr, int &found, typeRecord *&vn, int scope);
void searchGlobalVariable(string name, vector<typeRecord*> &globalVariables, int &found, typeRecord *&vn, int scope);
string eletypeMapper(eletype a);
void printSymbolTable(vector<funcEntry*> &funcEntryRecord, vector<typeRecord*> &globalVariables);
void addFunction(funcEntry* activeFuncPtr, vector<funcEntry*> &funcEntryRecord);
eletype compareTypes(eletype type1, eletype type2);
void SearchFunction(funcEntry* activeFuncPtr,vector<funcEntry*> &funcEntryRecord,int &found);
void populateOffsets(vector<funcEntry*> &funcEntryRecord, vector<typeRecord*> &globalVariables);
int varTypeMapper(varType a);
void ParameterSearch(string name, vector<typeRecord*> &parameterList, int &found, typeRecord *&pn);
void patchDataType(eletype type, vector<typeRecord*> &typeRecordList, int scope);
void insertGlobalVariables(vector<typeRecord*> &typeRecordList, vector<typeRecord*> &globalVariables);
void ComapareFunction(funcEntry* &activeFuncPtr,vector<funcEntry*> &funcEntryRecord,int &found);
void insertParameterTable(vector<typeRecord*> &typeRecordList, funcEntry* activeFuncPtr);
void CallVariableSearch(string name, funcEntry* activeFuncPtr, int &found, typeRecord *&vn, vector<typeRecord*> &globalVariables);
void insertSymbolTable(vector<typeRecord*> &typeRecordList, funcEntry* activeFuncPtr);