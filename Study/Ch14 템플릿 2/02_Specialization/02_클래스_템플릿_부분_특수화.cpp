/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 클래스 템플릿 부분 특수화
	클래스 템플릿의 부분 특수화
		부분적으로 특수화를 진행한 것

	전체 특수화가 부분 특수화보다 우선시 된다
*/

#include <iostream>
using namespace std;

template<typename T1, typename T2>
class MySimple {

public:
	void WhoAreYou() {

		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of T2: " << sizeof(T2) << endl;
		cout << "<typename T1, typename T2>" << endl;
	}
};

template<>
class MySimple<int, double> {

public:
	void WhoAreYou() {

		cout << "size of int: " << sizeof(int) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

template<typename T1>
class MySimple<T1, double> {

public:
	void WhoAreYou() {

		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<T1, double>" << endl;
	}
};


int main(void)
{

	MySimple<char, double> obj1;	// T1, double
	obj1.WhoAreYou();

	MySimple<int, long> obj2;		// T1, T2
	obj2.WhoAreYou();

	MySimple<int, double> obj3;		// int, double
									// 전체 특수화가 부분 특수화보다 우선 시 된다
	obj3.WhoAreYou();
	return 0;
}