#include <iostream> 
using namespace std; 
  
// base class  
class Vehicle  
{ 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
    Vehicle(int a,int b);
}; 
  
//base class 
class Fare 
{ 
    public: 
    Fare() 
    { 
        cout<<"Fare of Vehicle\n"; 
    } 
    class hello{
    public:
        hello(int a){

                }
        class thricess{
        public:
                thricess();
                
    };
    
    };
}; 
Fare::hello::thricess::thricess(){}

Vehicle::Vehicle(int a,int b){

}
// first sub class  
class Car: public Vehicle 
{ 
  
}; 
  
// second sub class 
class Bus: public Vehicle, public Fare 
{ 
      
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base class 
    Bus obj2, obj1(); 
    
    return 0; 
} 