/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 기초 클래스의 포인터로 객체를 참조
	앞의 내용 요약 및 복습
*/

#include <iostream>
using namespace std;

class Simple { };
class Complex : public Simple { };

class Base {

public:
	void BaseFunc() {

		cout << "Base Function" << endl;
	}
};

class Derived : public Base {

public:
	void DerivedFunc() {

		cout << "Derived Function" << endl;
	}
};

int main(void)
{

	// Simple 클래스를 선언할 때는 
	// Simple 클래스나 Simple 클래스의 유도 클래스를 new 키워드를 이용해 정의한다
	Simple* sim1 = new Simple;
	Simple* sim2 = new Complex;

	Base* bptr1 = new Derived;
	// bptr1->DerivedFunc();	// 컴파일 에러 
								// C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단
								// 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다
	// Derived dptr1 = bptr1;	// 컴파일 에러

	Derived* dptr2 = new Derived;
	Base* bptr2 = dptr2;

	return 0;
}