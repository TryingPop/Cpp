#include <iostream>
using namespace std;

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 매개변수의 디폴트 값
	디폴트 값 선언하는 다른 방법
*/

// 함수의 선언
int Add(int num1 = 1, int num2 = 2); 

int main()
{

	cout << "Add() : " << Add() << endl;
	cout << "Add(5) : " << Add(5) << endl;
	cout << "Add(1, 2) : " << Add(1, 2) << endl;

	return 0;
}

// 함수의 정의
int Add(int num1, int num2) {

	return num1 + num2;
}