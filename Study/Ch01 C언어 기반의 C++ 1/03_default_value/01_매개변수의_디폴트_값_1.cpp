#include <iostream>
using namespace std;

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 매개변수의 디폴트 값
	디폴트 값은 기본적으로 설정되어 있는 값
*/

int Add(int num1 = 1) {

	return num1;
}

int Add(int num1, int num2 = 2) {

	return num1 + num2;
}

int Multi(int num1 = 1, int num2 = 2) {

	return num1 * num2;
}

int main()
{

	cout << Add() << endl;
	// Add(2); // C#과 달리 호출이 모호하다는 에러 뜬다 
			   // C#에서는 Add(num1 = 1)이 호출된다

	cout << Multi() << endl;		// 1 * 2 = 2
	cout << Multi(2) << endl;		// 2 * 2 = 4
	cout << Multi(1, 2) << endl;	// 1 * 2 = 2

	return 0;
}