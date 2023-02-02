/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : static 멤버변수
	static 멤버변수의 또 다른 접근 방법
*/

#include<iostream>
using namespace std;

class SoSimple {

public:
	static int simObjCnt;

public:	// 불필요하지만 변수와 함수의 구분을 목적으로 삽입하기도 함
	SoSimple() {

		simObjCnt++;
	}
};

int SoSimple::simObjCnt = 0;

int main(void)
{

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;		// 0
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;		// 2
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;				// 2
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;				// 2
	return 0;
}