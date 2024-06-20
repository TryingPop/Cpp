/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : 반환형이 참조형(Reference Type)인 경우
	교재 p82 ~ 86

	함수의 반환형에도 참조형이 선언될 수 있다
	반환 값이 참조형인 경우
	반드시 변수에 저장해야하고, 해당 반환값은 상수와 다름없기 때문에
	참조자 선언으로 해당 값을 받을 수 없다
*/

#include <iostream>

using namespace std;

int& RefRetFuncOne(int& _ref)
{

	_ref++;
	return _ref;
}

int RefRetFuncTwo(int& _ref)
{

	_ref++;
	return _ref;
}

int main(void)
{

	int num1 = 1;
	int num2 = RefRetFuncOne(num1);
	int& ref2 = RefRetFuncOne(num1);
	RefRetFuncOne(num1);

	int num3 = RefRetFuncTwo(num1);
	// int& ref3 = RefRetFuncTwo(num1);	// 컴파일 에러
	RefRetFuncTwo(num1);

	num1 += 10;
	num2 += 100;
	num3 += 1000;

	cout << "num1: " << num1 << endl;	// 16
	cout << "num2: " << num2 << endl;	// 102
	cout << "num3: " << num3 << endl;	// 1005

	return 0;
}