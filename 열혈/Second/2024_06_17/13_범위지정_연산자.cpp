/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 범위지정 연산자(Scope Resolution Operator)의 또 다른 기능
	교재 p49 ~ 50

	지역변수의 이름이 전역변수의 이름과 같을 경우,
	전역변수는 지역변수에 의해 가려졌다

	그러나 범위지정 연산자를 통해 전역변수에도 접근할 수 있다
*/

#include <iostream>

using namespace std;

int num = 1;

int main(void)
{

	int num = 5;
	cout << "지역 변수 num: " << num << endl;		// 5
	cout << "전역 변수 num: " << ::num << endl;		// 1

	return 0;
}