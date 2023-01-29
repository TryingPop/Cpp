/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : self Reference
	객체 자신을 참조할 수 있는 참조자

	this 포인터를 이용해 객체가 자신의 참조에 사용할 수 있는 
	참조자의 반환문을 구성해보자
*/

#include<iostream>
using namespace std;

class SelfRef {

private:
	int num;

public:
	SelfRef(int n) : num(n) {

		cout << "객체생성" << endl;
	}

	SelfRef& Adder(int n) {

		num += n;
		return *this;
	}

	SelfRef& ShowTwoNumber() {

		cout << num << endl;
		return *this;
	}
};

int main(void)
{

	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();	// 5
	ref.ShowTwoNumber();	// 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	// 6,  8 
															// Adder(1), ShowTwoNumber(), Adder(2), ShowTwoNumber()
															// 순으로 메소드가 호출됨을 알 수 있다
	return 0;
}