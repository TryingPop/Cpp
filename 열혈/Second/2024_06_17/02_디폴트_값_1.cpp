/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 매개변수의 디폴트 값
	교재 p27 ~ 29

	C++ 함수에는 디폴트 값이라는 것을 설정할 수 있다
	디폴트 값이란 기본적으로 설정되어 있는 값을 의미한다

	매개변수에 디폴트 값이 설정되어 있으면, 
	선언된 매개변수의 수보다 적은 수의 인자전달이 가능하다
	그리고 전달되는 인자는 왼쪽에서부터 채워져 나가고,
	부족분은 디폴트 값으로 채워진다
*/

#include <iostream>

int Adder(int num1 = 1, int num2 = 2) 
{

	return num1 + num2;
}

int main(void)
{

	std::cout << Adder() << std::endl;		// 3
	std::cout << Adder(5) << std::endl;		// 7
	std::cout << Adder(3, 5) << std::endl;	// 8

	return 0;
}