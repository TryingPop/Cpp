/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : 포인터 연산자
	-> 포인터가 가리키는 객체의 멤버에 접근
	* 포인터가 가리키는 객체에 접근

	이 두 연산자의 오버로딩은 일반적인 연산자의 오버로딩과 약간의 차이가 있다
	둘 다 피 연산자가 하나인 단항 연산자의 형태로 오버로딩 된다

	교재 480p 참조하기

	아래는 오버로딩 방식의 예제이다
*/

#include <iostream>
using namespace std;

class Number {

private:
	int num1;
	int num2;
	int num3;

public:
	Number(int n1)
		:num1(n1), num2(0), num3(0) { 
	
		cout << "Create n1" << endl;
	}

	Number(int n1, int n2, int n3)
		: num1(n1), num2(n2), num3(n3) {

		cout << "Create n1, n2, n3" << endl;
	}

	void ShowData() const {

		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}

	// 교재 480p 에 의하면
	// 이 메소드로인해 private 멤버들에 접근가능하다고 한다
	// 참조는 가능하되 변경을 막을려면 const 선언을 해주면 된다
	Number* operator->() {

		return this;
	}

	Number& operator*() {

		return *this;
	}
};

int main(void)
{

	Number* num1 = new Number(20, 0, 0);	// create
	// 멤버 변수 접근 방법
	(*num1) = { 30, 0, 0 };					// create 
											// 생성자를 이용해 private 멤버변수에 
											// 값을 대입하는거 같다

	// num1 = 30;							// 컴파일 에러
	// num1->num;							// 컴파일 에러

	num1->ShowData();						// 30, 0, 0
	(*num1).ShowData();						// 30, 0, 0
	// num1.ShowData();						// 컴파일 에러

	Number num2(40, 2, 2);
	(*num2) = 50;							// create, 원래는 정의 안됨
	// num2 = { 50, 2 };					// 컴파일 에러
	// num2->num;							// 컴파일 에러

	(*num2).ShowData();						// 50, 2, 2 원래는 정의안됨
	num2.ShowData();						// 50, 2, 2 
	num2->ShowData();						// 50, 2. 2 원래는 정의안됨

	return 0;
}