/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : const_cast
	앞의 dynamic_cast나 static_cast와 형식이 비슷하다

	const_cast 연산자의 형식은 다음과 같다
		const_cast<T>(expr)

		const_cast는 const 성향을 제거하는 형 변환을 목적으로 사용한다

	const 선언으로 인한 형의 불일치가 발생해
	인자의 전달이 불가능한 경우에 유용하게 사용이된다
	또한 volatile의 성향을 제거하는데도 사용할 수 있다
	아래는 사용된 예제이다
*/

#include <iostream>
using namespace std;

void ShowString(char* str) {

	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2) {

	cout << n1 + n2 << endl;
}


int main(void)
{

	const char* name = "Lee Sung Ju";
	// ShowString(name);			// 호환 안되는 컴파일 에러
	// 반대로 ShowString의 인자가 const char*이고
	// name이 char*로 정의되어져 있으면 호환이 가능하다
	ShowString(const_cast<char*>(name));	// Lee Sung Ju

	const int& num1 = 100;
	const int& num2 = 200;

	// ShowAddResult(&num1, &num2);	// 호환 안되는 컴파일 에러
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));	// 300
	return 0;
}