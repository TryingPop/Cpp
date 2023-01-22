/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : const
	위치에 따른 const의 의미를 알아보자
*/

#include <iostream>
using namespace std;

int main(void)
{
	
	int val1 = 1;
	int val2 = 2;

	const int* num1 = &val1;
	num1 = &val2;				// num1의 주소가 val2의 주소로 바뀐다
	// *num1 = 20;				// 하지만 num1의 값을 변형 시켜 val1에 전달하는게 안된다

	int* const num2 = &val1;

	//num2 = &val2;				// num2에 다른 변수의 주소로 못바꾼다
	*num2 = 5;					// 반면 num2의 값을 변환시켜 val2의 값을 변환할 수 있다.

	const int* const num3 = &val1;
	// 앞의 예를 종합해서 보면 num3는 값 변경도 안되고 주소도 못바꾼다

	// 반면 val1은 이상없이 값 변경 가능하다
	val1 = val2;
}