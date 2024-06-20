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

	int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5;
	int ref1 = RefRetFuncOne(num1);
	int& ref2 = RefRetFuncOne(num2);	// num2을 참조한다!
	RefRetFuncOne(num5);

	int ref3 = RefRetFuncTwo(num3);
	// int& ref4 = RefRetFuncTwo(num4);	// 반환 값이 상수형 형태라 컴파일 에러
	RefRetFuncTwo(num5);

	ref1 += 10;
	ref2 += 20;
	ref3 += 30;

	cout << "ref1: " << ref1 << endl;	// 12
	cout << "ref2: " << ref2 << endl;	// 23
	cout << "ref3: " << ref3 << endl;	// 34

	cout << "num1: " << num1 << endl;	// 2
	cout << "num2: " << num2 << endl;	// 23
	cout << "num3: " << num3 << endl;	// 4
	cout << "num4: " << num4 << endl;	// 4
	cout << "num5: " << num5 << endl;	// 7
	return 0;
}