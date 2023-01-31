/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 복사생성자
	클래스명 변수명 = 같은 타입의 변수명
	으로 생성하면
	클래스명 변수명(같은 타입의 변수명) 형태로 읽는다
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) {
	}

	SoSimple(SoSimple& copy) 
		: num1(copy.num1), num2(copy.num2) {
	}

	void ShowSimpleData() {

		cout << num1 << endl;
		cout << num2 << endl;
	}

	void ShowSimpleAddr() {

		cout << &num1 << endl;
		cout << &num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;	// SoSimple sim2(sim1)으로 변환된다
	cout << "생성 및 초기화 직후" << endl;

	sim2.ShowSimpleData();

	// 
	cout << "sim1" << endl;
	cout << &sim1 << endl;
	sim1.ShowSimpleAddr();
	cout << "sim2" << endl;
	cout << &sim2 << endl;
	sim2.ShowSimpleAddr();
	return 0;
}