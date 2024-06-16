/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : const 참조자
	const 참조자의 상수 참조
*/

#include <iostream>
using namespace std;

int Add(const int& num1, const int& num2);

int main(void)
{

	// const 참조자
	const int num = 20;

	// int& ref = num;		// 변환할 수 있어서 컴파일에서 에러 뜬다
	const int& ref1 = num;	// 다음과 같이 변환하면 에러 없다

	// 참조자는 상수를 참조 못한다고 했는데, 아래와 같은 경우는 예외이다
	// 20은 literal이라 다음 행으로 넘어가면 사라지는 상수
	// const 참조자는 20을 포함하는 임시 변수를 생성한다
	// 왼쪽의 ref2가 생성된 임시변수를 참조함으로써
	// ref2는 10을 참조하고 있다
	const int& ref2 = 20;

	cout << "num : " << ref1 << endl;
	cout << "ref2 : " << ref2 << endl;

	cout << "Add(3, 4) : " << Add(3, 4) << endl;

	cout << "ref2 : " << ref2 << endl;
}

int Add(const int& num1, const int& num2) {

	return num1 + num2;
}