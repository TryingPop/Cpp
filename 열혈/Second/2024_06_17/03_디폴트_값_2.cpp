/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 디폴트 값은 함수의 선언부분에서만 표현하면 된다
	교재 p29

	디폴트 값은 함수의 선언부분에서만 표현하면된다
	만약 밑에 정의하는 곳에서 선언하면
	위에서 아래로 읽기에 컴파일 자체가 안된다

	그리고 아래에서 디폴트 값을 다시 넣거나 다른 값으로 변경하고자 한다면
	함수가 재정의 됐다고 컴파일 에러 뜬다
*/

#include <iostream>

int Adder(int _num1 = 1, int _num2 = 2);

int main(void)
{

	std::cout << Adder() << std::endl;		// 3
	std::cout << Adder(3) << std::endl;		// 5
	std::cout << Adder(6, 8) << std::endl;	// 14

	return 0;
}

int Adder(int _num1, int _num2)
{

	return _num1 + _num2;
}