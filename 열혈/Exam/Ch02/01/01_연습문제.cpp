/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : 교재 80p 문제1
	참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라
		1. 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
		2. 인자로 전달된 int형 변수의 부호를 바꾸는 함수
*/

// 1증가 
void Func1(int& num) {

	num++;
}

// 부호 변환 함수
void Func2(int& num) {

	num = -num;
}

// 잘 적용 되는지 확인
#include <iostream>
using namespace std;

int main(void)
{
	int val1 = 2;
	int val2 = 3;

	Func1(val1);
	Func2(val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
}