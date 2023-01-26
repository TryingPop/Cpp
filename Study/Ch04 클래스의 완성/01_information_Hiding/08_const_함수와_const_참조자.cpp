/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : const 함수와 const 참조자
	const 함수
		이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다
		멤버변수의 값을 변환 시키면 컴파일 에러가 발생
		또한 const 함수 내에서는 const가 아닌 함수의 호출이 제한된다

	const 참조자
		매개변수에 const를 붙이 참조자
		C++에서는 const 참조자를 대상으로 값의 변경 능력을 가진 함수의 호출을 허용하지 않는다
*/
#include <iostream>
using namespace std;

class SimpleClass {

private:
	int num;

public:
	void InitNum(int n) {

		num = n;
	}

	int GetNum() {

		return num;
	}

	void ShowNum() const {

		// cout << GetNum() << end; // 컴파일 에러 발생
									// GetNum 이 const 함수가 아니다
	}
};

class OtherClass {

private:
	int num;

public:
	// const 참조자
	void InitNum(const SimpleClass& simple) {

		// num = simple.GetNum();	// 컴파일 에러 발생
									// simple.GetNum 함수가 const 함수가 아니다
	}
};