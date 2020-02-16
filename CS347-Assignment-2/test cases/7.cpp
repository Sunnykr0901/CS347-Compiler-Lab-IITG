#include<bits/stdc++.h>
using namespace std;

class A{
public:
	class B{
	public:
		class C{
		public:
			C(){
			}
		}obj1,obj;
	}obj2;
}obj3;

class D: private A{
public:
	class E: private A{
	public:
		E();
	};
};
D::E::E(){}
int main(){}