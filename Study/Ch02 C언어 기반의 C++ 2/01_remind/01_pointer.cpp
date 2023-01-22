/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 포인터
	*의 의미와 &의 의미를 알아보자
*/

#include<iostream>
using namespace std;

int main(void)
{
	
	int num1 = 10;
	int num2 = 20;

	// int를 예로 들어보자, char, float, double 등 모두 같다
	// int* 변수명 여기서 int* 가 의미하는 것은 int형태의 주소라 보면 된다
	// int* 형 변수는 *변수명을 입력하는 것으로 값을 참조할 수 있다.
	int* ptr;	// 초기화 되지 않으면 읽을 수 없다

	// &가 의미하는 것은 변수의 주소라고 생각하면 된다
	cout << "num1의 주소" << &num1 << endl;
	cout << "num2의 주소" << &num2 << endl;

	ptr = &num1;
	cout << "ptr 주소" << ptr << endl;
	cout << "ptr 값" << *ptr << endl;

	ptr = &num2;
	cout << "ptr 주소" << ptr << endl;
	cout << "ptr 값" << *ptr << endl;
}