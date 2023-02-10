/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 가상 상속
	다음 예제의 모호함의 원인 파악해보기
*/

#include <iostream>
using namespace std;

class Base {

public:
	Base() {
		cout << "Base Constructor" << endl;
	}

	void SimpleFunc() {

		cout << "BaseOne" << endl;
	}
};

class MiddleDerivedOne : virtual public Base {

public:
	MiddleDerivedOne()
		: Base() {
	
		cout << "MiddleDerivedOne Constructor" << endl;
	}

	void MiddleFuncOne() {

		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base {

public:
	MiddleDerivedTwo()
		: Base() {

		cout << "MiddleDerivedTwo Constructor" << endl;
	}

	void MiddleFuncTwo() {

		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {

public:
	LastDerived()
		: MiddleDerivedOne(), MiddleDerivedTwo() {

		cout << "LastDerived Constructor" << endl;
	}

	void ComplexFunc() {

		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{

	cout << "객체생성 전 ....." << endl;
	LastDerived ldr;	// Base, MiddleOne, MiddleTwo, Last 순으로 호출된다 
						// Base는 한 번만 호출된다
						// Last 클래스가 Base를 간접적으로 두 번 상속한다
	cout << "객체생성 후 ....." << endl;
	ldr.ComplexFunc();	// virtual 선언이 안되어져 있다면 
						// MiddleDerivedOne::SimpleFunc처럼 어디 SimpleFunc를 호출하는지 명명해줘야한다
						// 가상 상속을 함으로써 1번 상속하게 했다
						// virtual 키워드가 없다면 모호하다는 컴파일 에러 발생하고 Base 클래스는 두번 호출된다
	return 0;
}