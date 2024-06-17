/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 함수 오버로딩
	교재 p23 ~ 26

	C언어에서는 동일한 이름의 함수가 정의되는 것을 허용하지 않는다
	두 함수의 이름이 같으면 컴파일 오류가 발생한다

	C++ 에서는 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 
	함수의 구분이 가능하기 때문에

	매개변수의 선언형태가 다르다면, 동일한 이름의 함수정의를 허용한다
	이를 가리켜 함수 오버로딩(Function Overloading)이라 한다

	C++은 호출할 함수를찾을 때, 함수의 이름, 매개변수의 선언으로 함수를 찾는다
	반면 C 언어는 함수의 이름으로만 찾아 함수 오버로딩이 불가능하며,
	이를 문법적으로 허용하지 않는다

	함수 오버로딩이 가능하려면 매개변수의 자료형 또는 개수가 달라야 한다
*/

#include <iostream>

void MyFunc(void)
{

	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char _c)
{

	std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int _a, int _b)
{

	std::cout << "MyFunc(int _a, int _b) called" << std::endl;
}

int main(void)
{

	MyFunc();
	MyFunc('A');
	MyFunc(1, 2);

	return 0;
}