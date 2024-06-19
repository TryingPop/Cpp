/*
날짜 : 2024. 6. 19
이름 : 배성훈
내용 : 참조자와 함수
	교재 p74 ~ 76

	변수와 참조자를 함께 선언하는 경우는 없다
	어디까지나 학습을 위한 코드였다
	참조자의 활용에는 함수가 큰 위치를 차지한다
	따라서 함수와 참조자의 관계를 보자

	앞에서 Call by value & Call by reference 함수 호출방식이 있었다
	Call by value는 값을 인자로 전달하는 함수의 호출방식이였고,
	Call by reference는 주소 값을 인자로 전달하는 함수의 호출방식이 었다

	Call by value의 형태로 정의된 함수의 내부에서는
	함수외부에 선언된 변수에 접근이 불가능하다

	따라서 두 변수에 저장된 값을 서로 바꿔서 저장할 목적으로 
	다음과 같이 함수를 정의하면 원하는 결과를 얻을 수 없다
		void SwapByValue(int _num1, int _num2)
		{

			int temp = _num1;
			_num1 = _num2;
			_num2 = temp;
			// Call by value
		}

	해당 함수를 main 함수에서 실행하면 변화가 없음을 알 수 있다
	그래서 필요한 것이 다음과 같은 Call by reference 기반의 함수이다
		void SwapByRef(int* _ptr1, int* _ptr2)
		{

			int temp = *_ptr1;
			*_ptr1 = *_ptr2;
			*_ptr2 = temp;
			// Call by reference
		}
	
	위 함수는 두 개의 주소 값을 받아서,
	그 주소 값이 참조하는 영역에 저장된 값을
	직접 변경하고 있다
	따라서 위 함수를 대상으로 다음의 main 함수를 실행하면
	변경됨을 확인할 수 있다
*/

#include <iostream>
#define endl '\n'

using namespace std;

void SwapByValue(int _num1, int _num2)
{

	int temp = _num1;
	_num1 = _num2;
	_num2 = temp;
	// Call by value
}

void SwapByRef(int* _ptr1, int* _ptr2)
{

	int temp = *_ptr1;
	*_ptr1 = *_ptr2;
	*_ptr2 = temp;
	// Call by reference
}

int main(void)
{

	int val1 = 10, val2 = 20;

	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 10, 20

	SwapByValue(val1, val2);
	cout << "SwapByValue" << endl;
	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 10, 20

	SwapByRef(&val1, &val2);
	cout << "SwapByRef" << endl;
	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 20, 10

	return 0;
}