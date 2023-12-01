/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : 전역변수가 필요한 상황
	static 설명에 앞서 전역 변수가 필요한 상황인 예제
*/

#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple {

public:
	SoSimple() {

		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex {

public:
	SoComplex() {

		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}

	SoComplex(SoComplex& copy) {

		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};

int main(void)
{

	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
	return 0;
}