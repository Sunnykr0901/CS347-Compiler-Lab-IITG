#include "symTabParser.h"

//Added by SSR

string eletypeMapper(eletype a){
    switch(a){
        case FLOATING  : return "float";
        case ERRORTYPE : return "error";
        case BOOLEAN   : return "bool";
        case NULLVOID  : return "void";
        case INTEGER   : return "int";
        default: return "default";
    }
}

int eletypeIntMapper(eletype a){
    switch(a){
        case INTEGER   : return 0;
        case FLOATING  : return 1;
        case NULLVOID  : return 2;
        case BOOLEAN   : return 3;
        case ERRORTYPE : return 4;
        default : return 999;
    }
}

eletype getEleType(string str){
    if(str=="0")
        return INTEGER;
    if(str=="1")
        return FLOATING;
    if(str=="2")
        return NULLVOID;
    return ERRORTYPE;
}

//Added by Mani

int getOffset(vector<funcEntry> &functionList, vector<typeRecord> &globalVariables, string funcname, string varname, int internaloffset, bool &isglobal){
    isglobal = false;
    for(auto it : functionList){
        if(it.name == funcname){
            for (auto it2 : it.variableList){
                if(it2->name == varname){
                    int offset = it.functionOffset - 4*( internaloffset + 1) - it2->varOffset;
                    return offset; 
                }
            }
            for (auto it2: it.parameterList){
                if(it2->name == varname){
                    int offset = it.functionOffset + 4*(it.numOfParam - internaloffset - 1) - it2->varOffset;
                    return offset; 
                }
            }
        }
    }   
    for(auto it : globalVariables){
        if(it.name == varname){
            isglobal = true;
            return 0;
        }
    }
    cout << "Variable " << varname << " not found in " << funcname << endl;
    return -1;
}

int getFunctionOffset(vector<funcEntry> &functionList,string funcname){
    for(auto it : functionList){
        if(it.name == funcname){
            return it.functionOffset;
        }
    }
    return -1;
}

void printVector(vector<funcEntry> &functionprintList){
    for(auto funcRecord : functionprintList){
        cout << "$$" << endl;
        cout << "_" << funcRecord.name << " " << eletypeMapper(funcRecord.returnType) << " ";
        cout << funcRecord.numOfParam << " " << funcRecord.functionOffset << endl;
        cout << "$1" << endl;
        for(auto varRecord : funcRecord.parameterList){
            cout <<varRecord->name << " " << eletypeIntMapper(varRecord->eleType) << " " ;
            cout << varRecord->scope << " " << varRecord->varOffset << endl;
        }
        cout << "$2 " << funcRecord.variableList.size() << endl;
        for(auto varRecord : funcRecord.variableList){
            cout <<varRecord->name << " " << eletypeIntMapper(varRecord->eleType) << " " ;
            cout << varRecord->scope << " " << varRecord->varOffset << endl;
        }
    }
}

//Added by Siddarth

void readSymbolTable(vector<funcEntry> &functionList, vector<typeRecord> &globalVariables){
    ifstream ifile;
    ifile.open ("../firstPass/output/symtab.txt");
    string str;
    bool isglobal = false;
    while(ifile >> str){
        if(str=="$$"){
            funcEntry fe;
            ifile >> fe.name;
            if(fe.name == "GLOBAL"){
                isglobal = true;
            }
            else{
                isglobal = false;
            }
            string stu;
            ifile >> stu;
            fe.returnType = getEleType(stu);
            ifile >> fe.numOfParam;
            ifile >> fe.functionOffset;
            ifile >> stu;
            if(isglobal){
                for(int i=0;i<fe.numOfParam;i++){
                    typeRecord ntype;
                    string eltype;
                    ifile >> ntype.name;
                    ifile >> eltype;
                    ntype.eleType = getEleType(eltype);
                    
                    ifile >> ntype.scope;
                    ifile >> ntype.varOffset;
                    globalVariables.push_back(ntype);
                }
                for(auto it : globalVariables){
                    cout << "Global Variable Name : "<< it.name << endl;
                }
            }
            else{
                (fe.parameterList).resize(fe.numOfParam);
                for(int i=0;i<fe.numOfParam;i++){
                    fe.parameterList[i] = new typeRecord;
                    ifile >> (fe.parameterList[i])->name;
                    string sty;
                    ifile >> sty;
                    (fe.parameterList[i])->eleType= getEleType(sty);
                    ifile >> (fe.parameterList[i])->scope;
                    ifile >> (fe.parameterList[i])->varOffset; 
                }
            }
            ifile >> stu;
            int lim;
            ifile >> lim;
            fe.variableList.resize(lim);
            for(int i=0;i<lim;i++){
                fe.variableList[i] = new typeRecord;
                ifile >> (fe.variableList[i])->name;
                string sty;
                ifile >> sty;
                (fe.variableList[i])->eleType= getEleType(sty);
                ifile >> (fe.variableList[i])->scope;
                ifile >> (fe.variableList[i])->varOffset;
            }
            if(!isglobal){
                functionList.push_back(fe);
            }
        }
    }
}

int getParamOffset(vector<funcEntry> &functionList, string funcname){
    for(auto it : functionList){
        if(it.name == funcname){
            return 4*(it.numOfParam);
        }
    } 
    return 0;
}

