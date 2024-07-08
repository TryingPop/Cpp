/*
날짜 : 2024. 7. 8
이름 : 배성훈
내용 : this 포인터의 이해
	교재 p196 ~ 

	멤버함수 내에서는 this 라는 이름의 포인터를 사용할 수 있는데,
	이는 객체 자신을 가리키는 용도로 사용되는 포인터이다

	this는 그 주소 값과 자료형이 정해져 있지 않은 포인터이다
*/

#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{

private:
	int num;

public:
	SoSimple(int n) : num(n)
	{

		cout << "num = " << num << ", ";
		cout << "address = " << this << endl;
	}

	void ShowSimpleData()
	{

		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{

		return this;
	}
};

int main(void)
{

	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();

	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();

	return 0;
}