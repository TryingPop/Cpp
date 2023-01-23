/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : new와 참조자
	포인터 없이 힙에 할당된 변수 접근
*/

#include <iostream>
using namespace std;

int main(void) 
{

	int* ptr = new int;
	int& ref = *ptr;
	ref = 20;
	cout << *ptr << endl;	// 20

	return 0;
}