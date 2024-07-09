/*
날짜 : 2024. 7. 9
이름 : 배성훈
내용 : Self-Reference의 반환
	교재 p199 ~ 201

	Self-Reference란 객체 자신을 참조할 수 있는 참조자를 의미한다
	this 포인터를 이용해서 객체가 자신의 참조에 사용할 수 있는 
	참조자의 반환문을 구성할 수 있다

	아래 예제는 객체가 반환하는 참조 값을 대상으로 다양한 방법으로
	멤버함수를 호출했다
*/

#include <iostream>

using namespace std;

class SelfRef
{

private:
	int num;

public:
	SelfRef(int n) : num(n)
	{

		cout << "객체 생성" << endl;
	}

	SelfRef& Adder(int n)
	{

		num += n;
		return *this;
	}

	SelfRef& ShowTwoNumber()
	{

		cout << num << endl;
		return *this;
	}
};

int main(void)
{

	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

	return 0;
}