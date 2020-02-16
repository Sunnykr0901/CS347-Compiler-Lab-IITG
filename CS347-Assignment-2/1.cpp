#include <iostream>
using namespace std;

class Complex
{
  private:
  int real, imag;

  public:
  Complex(int r , int i )
  {
    real = r;
    imag = i;
  }
  void print() { cout << real << " + i" << imag << endl; }

  // The global operator function is made friend of this class so
  // that it can access private members
  Complex();
  
};


int main()
{
  Complex c1(10, 5), c2(2, 4),c3;
  //Complex c3 = c1 + c2; // An example call to "operator+"
  //c3.print();
  return 0;
}