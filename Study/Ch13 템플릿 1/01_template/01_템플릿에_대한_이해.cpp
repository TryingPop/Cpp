/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 템플릿에 대한 이해
	템플릿을 이용해
	int형과 double형 덧셈을 진행하는 Add함수를 만들어보자  

	함수를 템플릿으로 정의하면, 
	호출마다 함수가 존재하는지 판단하고 존재하지 않으면 함수를 만든다
	만약 함수가 존재하면 기존의 만들어진 함수를 호출한다

	그리고 함수의 생성은 컴파일에서 생성된다
	따라서 템플릿을 이용하면 컴파일에서만 속도가 느려지고
	실행 속도가 느려지는건 아니다
*/

#include <iostream>

using namespace std;

// typename 말고 class 를 이용해도 된다
// T 말고도 다른 문자 이용가능
template <typename T>
T Add(T num1, T num2) {

	return num1 + num2;
}

int main(void)
{

	cout << Add<int>(15, 20) << endl;			// 35
	cout << Add<double>(2.9, 3.7) << endl;		// 6.6
	cout << Add<int>(3.2, 3.2) << endl;			// 6
	cout << Add<double>(3.14, 2.75) << endl;	// 5.89

	cout << Add(15, 20) << endl;				// 35
	cout << Add(2.9, 3.7) << endl;				// 6.6
	cout << Add(3.2, 3.2) << endl;				// 6.4
	cout << Add(3.14, 2.75) << endl;			// 5.89
	return 0;
}