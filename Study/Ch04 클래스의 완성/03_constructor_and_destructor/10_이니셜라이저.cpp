/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 이니셜라이저
	멤버변수로 참조자를 선언할 수 있게한다
*/

#include <iostream>
using namespace std;

class AAA {

public:
	AAA() {

		cout << "empty object" << endl;
	}
	
	void ShowYourName() {

		cout << "I`m class AAA" << endl;
	}
};

class BBB {

private:
	AAA& ref;
	const int& num;

public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n) { }

	void ShowYourName() {

		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void) {

	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
}