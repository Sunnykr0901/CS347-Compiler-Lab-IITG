#include <iostream>
class classes{

};



class Area
{
  private:
    int length;
    int breadth;

  public:
    // Constructor with no arguments
    Area() {}
   
    Area a64l();
    // Constructor with two arguments
    Area(int l, int b) : length(l), breadth(b) {}

    void GetLength()
    {
        cout << "Enter length and breadth respectively: ";
        cin >> length >> breadth;
    }

    int AreaCalculation() { return length * breadth; }

    void DisplayArea(int temp)
    {
        cout << "Area: " << temp << endl;
    }
};





class Child : public Area
{
  public:
    int id_c;

    void operator+(){
        
    }
};

class A
{
    int x;

  public:
    void setX(int i) { x = i; }
    void print() { cout << x; }
};

class B : public A
{
  public:
    B() { setX(10); }
};

class C : public A
{
  public:
    C() { setX(20); }
};

class D : public B, public C
{
};

class outside
{
  public:
    class nested
    {
      public:
        static int x;
        static int y;
        int f();
        int g();
    };
};
int outside::nested::x = 5;
int outside::nested::f() { return 0; };

class AA
{
  private:
    class BB
    {
    };
    BB *z;

    class CC : private BB
    {
      private:
        BB y;
        //      A::B y2;
        CC *x;
        //      A::C *x2;
    };
};

int main()
{
    Area A1, A2(2, 1);
    int temp;

    cout << "Default Area when no argument is passed." << endl;
    temp = A1.AreaCalculation();
    A1.DisplayArea(temp);

    cout << "Area when (2,1) is passed as argument." << endl;
    temp = A2.AreaCalculation();
    A2.DisplayArea(temp);

    return 0;
}