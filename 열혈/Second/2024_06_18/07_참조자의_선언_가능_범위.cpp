/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : 참조자의 선언 가능 범위
	교재 p71 ~ 73

	참조자의 수에는 제한이 없다
	그리고 참조자를 대상으로도 참조자를 선언할 수있다
	하지만 필요 이상으로 참조자를 선언하는 것은 바람직하지 않으며,
	참조자를 대상으로 또 다른 참조를 만드는 일은 흔히 필요하지는 않다

	참조자는 변수에 대해서만 선언이 가능하고,
	선언됨과 동시에 누군가를 참조해야만 한다

		int& ref = 20;
		int& ref;
		int& ref = NULL;
	등은 불가능하다
	
	그리고 참조의 대상을 바꾸는 것도 불가능하다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int arr[3] = { 1, 2, 3 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];


	cout << ref1 << endl;		// 1
	cout << ref2 << endl;		// 2
	cout << ref3 << endl;		// 3

	int& nref1 = ref1;			// 참조자에 대해 새로운 참조자 선언
	// &nref1 = ref2;			// 컴파일 에러 발생
	nref1 = ref2;				// 값이 변경된다

	cout << ref1 << endl;		// 2
	cout << ref2 << endl;		// 2

	// int& nref2;				// 이니셜라이저 필요하다고 컴파일 에러 발생
	// int& nref3 = 20;			// 비 const 참조에 대한 초기값은 lvalue?
	// int& ref4 = NULL;		// 비 const 참조에 대한 초기값은 lvalue?

	return 0;
}