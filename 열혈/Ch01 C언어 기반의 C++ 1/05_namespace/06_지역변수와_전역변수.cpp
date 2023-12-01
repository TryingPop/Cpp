#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 범위 지정 연산자
	지역변수와 전역변수
*/

// 전역변수
int val = 0;

int SimpleFunc(void) {

	// 지역 변수
	// 함수가 종료되면 지역 변수는 메모리에서 사라진다
	int val = 20;
	val += 3;
	// 전역 변수
	::val += 7;

	return 0;
}

int main()
{

	cout << "전역 변수 val : " << val << endl;	// 0
	SimpleFunc();
	cout << "전역 변수 val : " << val << endl;	// 7
	return 0;
}
