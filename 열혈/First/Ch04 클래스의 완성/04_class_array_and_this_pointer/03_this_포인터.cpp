/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : this 포인터
	멤버 함수 내에서는 this라는 이름의 포인터를 사용할 수 있다
	이는 객체 자신을 가리키는 용도
	아래는 this 포인터의 예시이다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) : num(n) {

		cout << "num = " << num << ", ";
		cout << "address = " << this << endl;
	}

	void ShowSimpleData() {

		cout << num << endl;
	}

	SoSimple* GetThisPointer() {

		return this;
	}
};

int main(void)
{

	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();	// sim1 객체의 주소 값 저장
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();	// sim2 객체의 주소 값 저장
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}