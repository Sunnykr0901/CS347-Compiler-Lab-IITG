#pragma once
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

#define KCYN  "\x1B[36m"
#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST

#define FMAG(x) KMAG x RST
#define KWHT  "\x1B[37m"

#define RST  "\x1B[0m"
#define FBLU(x) KBLU x RST
#define FYEL(x) KYEL x RST
#define KYEL  "\x1B[33m"
#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define FWHT(x) KWHT x RST
#define FCYN(x) KCYN x RST

class registerSet {
private:
    vector<int> tempRegister;
    vector<int> floatRegister;
public:
    registerSet(){
        tempRegister.clear();
        for(int i=9; i>=0; i--){
            tempRegister.push_back(i);
        }
        floatRegister.clear();
        for(int i=10; i>=0; i--){
            if(i==0||i==12){
                continue;
            }
            floatRegister.push_back(i);
        }
    }
    string getRegister();
    string getFloatRegister();
    void freeRegister(string s);
};

void mergeSwitch(vector<pair<string,int>> *&receiver,vector<pair<string,int>> *&donor); 
void backpatch(vector<int> *&, int, vector<string> &);
void gen(vector<string> &, string ,int &);
void merge(vector<int> *&, vector<int> *&);

 
