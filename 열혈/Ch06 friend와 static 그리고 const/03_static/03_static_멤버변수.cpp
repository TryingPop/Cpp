/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : static 멤버변수(클래스 변수)
	일반적인 멤버변수와 달리 클래스당 하나씩만 생성

	static 변수의 초기화 방법 주의
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	static int simObjCnt;

public:
	SoSimple() {

		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

int SoSimple::simObjCnt = 0;	// static 변수의 초기화 방법
								// 이거 안해주면 vs에서는 에러뜬다
								// 다른 곳은 쓰레기값이 초기값이라 알 수 없는 값

class SoComplex {

private:
	static int cmxObjCnt;

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

int SoComplex::cmxObjCnt = 0;

class SoOdd {

private:
	static int oddObjCnt;

public:
	SoOdd() {
		oddObjCnt = 0;	// static변수는 이미 메모리 공간에 할당이 이루어진 변수라 객체가 생성될때마다 매번 0으로 초기화
		oddObjCnt++;
		cout << oddObjCnt << "번째 SoOdd 객체" << endl;
	}
};

int SoOdd::oddObjCnt = 0;

int main(void) 
{

	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	SoOdd odd1;
	SoOdd odd2;
	return 0;
}

