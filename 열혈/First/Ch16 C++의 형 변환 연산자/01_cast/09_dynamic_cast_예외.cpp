/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : dynamic_cast
	dynamic_cast에서 발생할 수 있는 예외상황
*/

#include <iostream>
using namespace std;

class SoSimple {

public:
	virtual void ShowSimpleInfo() {

		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {

public:
	void ShowSimpleInfo() {

		cout << "Socomplex Derived Class" << endl;
	}
};

int main(void)
{

	SoSimple simObj;
	SoSimple& ref = simObj;

	try {

		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);	// 예외 발생
															// NULL 값이 전달된다
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt) {

		cout << expt.what() << endl;	// what메소드는 예외의 원인을 문자열로 반환
										// Bad dynamic_cast!
	}
	return 0;
}