/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : 교재 80p 문제1
	참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라
		1. 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
		2. 인자로 전달된 int형 변수의 부호를 바꾸는 함수
*/

#include<iostream>
using namespace std;

void IncreOne(int& num) {

	num++;
}

void InverSign(int& num) {

	num *= -1;
}

int main(void)
{

	int val = 20;
	IncreOne(val);
	cout << val << endl;	// 21

	InverSign(val);
	cout << val << endl;	// -21
	return 0;
}