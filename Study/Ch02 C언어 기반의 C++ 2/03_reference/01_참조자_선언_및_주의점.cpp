/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : 참조자
	자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름
	참조자 선언 시 주의점
		1. 선언된 참조자는 다른 대상을 참조하지 못한다
		2. 참조자는 선언 시 정의 해줘야한다
		3. 참조자는 상수를 참조 못한다
		4. 참조자는 포인터처럼 NULL로 초기화 못한다
*/

#include <iostream>
using namespace std;

int main(void) 
{

	int val1 = 1020;

	// 참조자 선언 방법
	int& num1 = val1;
	
	num1 = 3047;

	// 같은 값을 갖는다
	cout << "VAL : " << val1 << endl;
	cout << "REF : " << &val1 << endl;

	cout << "VAL : " << num1 << endl;
	cout << "REF : " << &num1 << endl;


	int val2 = 2040;

	return 0;
}