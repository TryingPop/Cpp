/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : 참조자의 선언 가능 범위
	교재 p73 ~ 74

	포인터 변수도 변수이기 때문에 참조자의 선언이 가능하다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;		// 12
	cout << *pref << endl;		// 12
	cout << **dpref << endl;	// 12

	return 0;
}