/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : protected로 선언된 멤버가 허용하는 접근의 범위
	private : 자신만 접근 가능
	protected : 유도 클래스에서도 접근 가능, 외부에서는 접근 불가능
	public : 어디에서도 접근 가능

	기초 클래스와 이를 상속하는 유도 클래스 사이에서도 정보은닉은 지켜지는 게 좋다
*/

#include <iostream>
using namespace std;

class Base {

private:
	int num1;

protected:
	int num2;

public:
	int num3;

	void ShowData() {

		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}
};

class Derived : public Base {

public:
	void ShowBaseMember() {

		// cout << num1 << endl; // 컴파일 에러
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

