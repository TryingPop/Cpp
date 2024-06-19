/*
날짜 : 2024. 6. 19
이름 : 배성훈
내용 : Call by address? Call by reference!
	교재 p76 ~ 79

	Call by reference 형태의 함수호출이
	Call by address라 불리는 경우를 종종 본다

	C++의 참조자(reference) 기반의 함수호출과 구분을 위함인데
	주소 값을 전달하는 함수의 호출형태를 가리켜 여전히 Call by reference라 표현한다

		int* SimpleFunc(int* _ptr);
	이처럼 선언된 함수가 Call by value 인지 Call by reference 인지는 함수 정의를 봐야한다
	만약
		int* SimpleFunc(int* _ptr)
		{

			return _ptr + 1;
		}

	로 정의되어져 있다면 Call by reference로 보다는 Call by value로 보는 것이 옳다
	함수의 연산 주체는 값(value)인데, 그 값이 주소 값일 뿐이다
	int형이니 4가 증가한 주소 값이 된다

	주소 값을 이용해서 함수 외부에 선언된 변수에 접근하는 Call by reference와는 거리가 멀다
	반면 다음처럼 정의되면 Call by reference이다
		int* SimpleFunc(int* _ptr)
		{

			if (_ptr == NULL) return NULL;
			
			*_ptr = 20;
			return _ptr;
		}

	이 함수에서는 주소 값을 이용해서 함수 외부에 선언된 변수를 참조(reference) 했으니,
	이는 분명히 Call by reference이다

	본래 C언어에서 말하는 Call by reference는 다음의 의미를 지닌다
	주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출

	즉 주소 값이 외부 변수의 참조도구로 사용되는 함수의 호출을 뜻한다
	주소 값이 전달된 사실이 중요한게 아니라, 
	주소 값이 참조의 도구로 사용되었다는 사시링 중요한 것이다

	C++에서는 두 가지 방식으로 Call by reference 함수정의가 가능하다
	void SwapByRef2(int& _ref1, int& _ref2)
	{

		int temp = _ref1;
		_ref1 = _ref2;
		_ref2 = temp;
		// Call by reference
	}

	참조자는 선언과 동시에 변수로 초기화되어야한다
	매개변수는 함수가 호출되어야 초기화가 진행되는 변수들이다
	그래서 위 매개변수 선언은 초기화가 이뤄지지 않은 것이 아니라,
	함수호출 시 전달되는 인자로 초기화를 하겠다는 의미의 선언이다

	이처럼 C++에는 Call by reference의 구현방법에 참조자를 이용하는 방법과
	주소 값을 이용하는 방법, 이렇게 두 가지가 상존한다
*/

#include <iostream>

using namespace std;

void SwapByRef2(int& _ref1, int& _ref2)
{

	int temp = _ref1;
	_ref1 = _ref2;
	_ref2 = temp;
}

int main(void) 
{

	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	
	return 0;
}