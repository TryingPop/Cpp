/*
날짜 : 2024 .6. 18
이름 : 배성훈
내용 : C언어의 복습 (const 키워드)
	교재 p62 ~ 63

	먼저 키워드 const의 의미를 보자
		cont int num = 10;
		cont int* ptr1 = &val1;
		int* const ptr2 = &val2;
		const int* const ptr3 = &val3;

	의 차이점을 보자

	const int num = 10의 경우
	num 을 상수 취급한다는 의미이다
	이는 num의 값을 수정할 수 없다

	const int* ptr1은 ptr1이 가리키는 대상의 값을 상수취급해서 ptr1으로는 수정할 수 없다
	하지만 ptr1 가리키는 대상은 바꿀 수 있다
	ptr1으로만 가리키는 값을 수정 못할 뿐!이다!

	int* const ptr2는 ptr2가 가리키는 대상을 상수 취급해서 ptr2의 대상을 수정할 수없다
	하지만 ptr2가 가리키는 대상은 바꿀 수 있다

	const int* const ptr3은 ptr3이 가리키는 대상을 변경할 수 없다
	그리고 ptr3가 가리키는 대상을 ptr3로는 바꿀 수 없다
*/

#include <iostream>

#define endl '\n'
using namespace std;

int main(void)
{

	int num1 = 10, num2 = 100;
	
	const int* ptr1 = &num1;
	ptr1 = &num2;
	// *ptr1 = 30;				// 컴파일 에러
	cout << "ptr1: " << *ptr1 << endl;
	num1 = 50;					// ptr1로만 수정 못할 뿐이다!

	int* const ptr2 = &num1;
	// ptr2 = &num2;			// 컴파일 에러
	*ptr2 = 20;

	cout << "ptr2: " << *ptr2 << endl;

	const int* const ptr3 = &num1;
	// ptr3 = &num2;
	// *ptr3 = 30;
	cout << "ptr3: " << *ptr3 << endl;
}