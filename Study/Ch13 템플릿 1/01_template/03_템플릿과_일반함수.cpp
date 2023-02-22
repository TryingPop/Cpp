/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 템플릿 함수와 일반함수의 차이
	템플릿을 정의한 상황에서 일반함수까지 정의하는 것은 바람직하지 못하다
	하지만 컴파일러에 의해서 만들어지는 템플릿 함수가 일반함수와 구분되는 사실을 보기 위해 만든 예제
*/

#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) {

	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2) {

	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2) {

	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{

	cout << Add(5, 7) << endl;				// Add(int num1, int num2)
	cout << Add(3.7, 7.5) << endl;			// Add(double num1, double num1)
	cout << Add<int>(5, 7) << endl;			// T Add(T num1, T num2)
	cout << Add<double>(3.7, 7.5) << endl;	// T Add(T num1, T num2)

 	return 0;
}