/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 다중상속의 문제점
	멤버 접근의 문제
		두 클래스에 동일한 이름의 멤버가 있는 경우 발생하는 문제이다
*/

#include<iostream>
using namespace std;

class BaseOne {

public:
	void SimpleFunc() {

		cout << "BaseOne" << endl;
	}
};

class BaseTwo {

public:
	void SimpleFunc() {

		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo {

public:
	void ComplexFunc() {

		// SimpleFunc(); // 컴파일 에러
		// 해결방법
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{

	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}