/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : 참조
	참조의 정보

*/

#include <iostream>
using namespace std;

int main(void)
{

	int num = 1;
	int& ref = num;

	// 변수 num을 참조할 수 잇는 참조 값이 참조자 ref에 전달되어
	// 참조자 변수 ref가 변수 num을 참조하게 된다

	cout << &num << endl;

	cout << "ref" << endl;
	cout << ref << endl;
	cout << &ref << endl;
	return 0;
}