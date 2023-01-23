/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : 참조자
	배열과 포인터를 참조하는 예제
*/

#include <iostream>
using namespace std;

int main(void)
{

	// 배열 참조하는 예제
	int arr[3] = { 1, 3, 5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << "ref1 : " << ref1 << endl;
	cout << "ref2 : " << ref2 << endl;
	cout << "ref3 : " << ref3 << endl;
	cout << endl << endl;

	// 포인터 참조하는 예제
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dref) = dptr;

	// **를 빼면 포인터의 주소를 받아온다
	cout << "ref value: " << ref << endl;
	cout << "pref value: " << *pref << endl;
	cout << "dref value: " << **dref << endl;

	return 0;
}