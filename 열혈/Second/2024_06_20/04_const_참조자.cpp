/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : const 참조자의 또 다른 특징
	교재 p88 ~ 89

	const 선언을 통해서 변수 num을 상수화 했는데,
	다른 참조자 ref를 통해 이를 변경한다면 num의 상수화는 의미가 없다
	C++ 컴파일러는 해당 부분을 허용하지 않는다

	num이 상수로 선언되면 num의 참조자도 const 선언만 허용하고 있다
	const 선언이 없으면 컴파일 에러를 일으킨다
*/

#include <iostream>

using namespace std;

int main(void)
{

	const int num1 = 10;
	// int& ref1 = num1;				// 컴파일 에러 발생
	const int& ref1 = num1;				// 이상없이 잘된다

	int num2 = 10;
	const int& ref2 = num2;

	num2 = 20;
	// ref2 = 100;						// 컴파일 에러 발생

	cout << "num1: " << num1 << endl;	// 10
	cout << "ref1: " << ref1 << endl;	// 10

	cout << "num2: " << num2 << endl;	// 20
	cout << "ref2: " << ref2 << endl;	// 20

	return 0;
}