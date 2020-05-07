//Added by Shubham
#include <stdio.h>
#include <vector>
#include <fstream>
#include <utility>
#include <stack>
#include <iostream>
using namespace std;

#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KMAG  "\x1B[35m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define RST   "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KRED  "\x1B[31m"

#define FRED(x) KRED x RST
#define FCYN(x) KCYN x RST
#define FMAG(x) KMAG x RST
#define FYEL(x) KYEL x RST
#define FWHT(x) KWHT x RST
#define FBLU(x) KBLU x RST
#define FGRN(x) KGRN x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

enum Tag {PARAMAETER, VARIABLE};
enum varType {SIMPLE, ARRAY};
enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};

struct typeRecord {
    int varOffset;
    int scope;
    eletype eleType;
    string name;
}; 

struct funcEntry {
    int numOfParam;
    eletype returnType;
    string name;
    int functionOffset;
    vector <typeRecord*> variableList;
    vector <typeRecord*> parameterList;
}; 

string eletypeMapper(eletype a);
eletype getEleType(string x);
int eletypeIntMapper(eletype a);

int getOffset(vector<funcEntry> &functionList, vector<typeRecord> &globalVariables, string functionName, string variableName, int internalOffset, bool &isGlobal);
int getFunctionOffset(vector<funcEntry> &functionList, string functionName);
void readSymbolTable(vector<funcEntry> &functionList, vector<typeRecord> &globalVariables);
void printVector(vector<funcEntry> &functionList);
int getParamOffset(vector<funcEntry> &functionList, string functionName);