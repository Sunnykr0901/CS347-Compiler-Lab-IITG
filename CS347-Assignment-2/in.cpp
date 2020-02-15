// C++ Implementation to show that a derived class 
// doesn’t inherit access to private data members.  
// However, it does inherit a full parent object 

class A  
{ 
public: 
    int x; 
    void func();
protected: 
    int y; 
private: 
    int z; 
}; 

A x(5);
A func();

void A :: func(){

}

void func1(){

}
void func1(int a){

}
  
class B : public A 
{ 
    // x is public 
    // y is protected 
    // z is not accessible from B 
    void func();
}; 
  
class C : protected A 
{ 
    // x is protected 
    // y is protected 
    // z is not accessible from C 
}; 
  
class D : private A    // 'private' is default for classes 
{ 
    // x is private 
    // y is private 
    // z is not accessible from D 
}; 

int main()
{
    return 0;
}