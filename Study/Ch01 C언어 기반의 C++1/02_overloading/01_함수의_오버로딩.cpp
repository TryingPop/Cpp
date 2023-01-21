#include <iostream>
using namespace std;

/*

날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 함수의 오버로딩
	함수와 매개변수 선언을 보고 함수를 찾아서 가능한 방법
*/

// 오버로딩할 함수들 선언 
void MyFunc(void) {

	cout << "MyFunc(void) called" << endl;
}

void MyFunc(char c) {

	cout << "MyFunc(char c) called" << endl;
}

void MyFunc(int a, int b) {

	cout << "MyFunc(int a, int b) called" << endl;
}

int main() 
{

	// 오버로딩 결과 확인
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}