/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : this 포인터
	this 포인터의 사용 예제

	this 포인터를 이용하면
	매개변수의 이름을 멤버 변수로 이용가능
*/

#include <iostream>
using namespace std;

class TwoNumber {

private:
	int num1;
	int num2;

public:
	TwoNumber(int num1, int num2) {

		this->num1 = num1;
		this->num2 = num2;
	}

	/*
	TwoNumber(int num1, int num2) 
		: num1(num1), num2(num2)
	{
		// empty
	}
	*/

	void ShowTwoNumber() {

		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void) 
{

	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}