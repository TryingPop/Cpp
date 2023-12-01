/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 함수 템플릿과 템플릿 함수의 차이
	함수의 템플릿
		함수를 만드는 도구이다
		함수의 기능은 결정되어져 있지만, 자료형은 결정되어 있지 않아 다양한 자료형의 함수를 만들어낼 수 있다

	템플릿 함수
		템플릿을 기반으로 컴파일러가 만들어 내는 함수
*/

#include <iostream>
using namespace std;

// 함수의 템플릿
template <typename T>
T Add(T num1, T num2) {

	return num1 + num2;
}

int main(void)
{

	cout << Add<int>(15, 20) << endl;			// 템플릿 함수 Add(int num1, int num2) 생성
	cout << Add<double>(3.7, 7.5) << endl;		// 템플릿 함수 Add(double num1, double num2) 생성
	cout << Add<int>(3.2, 3.2) << endl;			// 템플릿 함수 Add(int num1, int num2) 함수 호출
	cout << Add<double>(3.14, 2.75) << endl;	// 템플릿 함수 Add(double num1, double num2) 함수 호출

	cout << Add(15, 20) << endl;				// 템플릿 함수 Add(int num1, int num2) 함수 호출
	cout << Add(3.7, 7.5) << endl;				// 템플릿 함수 Add(double num1, double num2) 함수 호출
	cout << Add(3.2, 3.2) << endl;				// 템플릿 함수 Add(double num1, double num2) 함수 호출
	cout << Add(3.14, 2.75) << endl;			// 템플릿 함수 Add(double num1, double num2) 함수 호출
	return 0;
}