/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : 교재 80p 문제3
	문제의 제시에 앞서 먼저 다음 코드를 보자
	int main(void)
	{
		int num1 = 5;
		int* ptr1 = &num1;
		int num2 = 10;
		int* ptr2 = &num2;
		...
	}
	위의 코드를 보면 ptr1과 ptr2가 각각 num1과 num2를 가리키고 있다.
	이 때 ptr1과 ptr2를 대상으로 다음과 같이 함수를 호출하고 나면,
		SwapPointer(ptr1, ptr2);
	ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해보자.
*/

#include <iostream>
using namespace std;

void SwapPointer(int* (&pref1), int* (&pref2)) {

	int* ptr = pref1;
	pref1 = pref2;
	pref2 = ptr;
}

int main(void) 
{

	int num1 = 5;
	int* ptr1 = &num1;

	int num2 = 10;
	int* ptr2 = &num2;

	cout << *ptr1 << endl;	// 5
	cout << *ptr2 << endl;	// 10

	SwapPointer(ptr1, ptr2);

	cout << *ptr1 << endl;	// 10
	cout << *ptr2 << endl;	// 5
	return 0;
}