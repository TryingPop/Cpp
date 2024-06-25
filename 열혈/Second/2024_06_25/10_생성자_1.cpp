/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 생성자의 이해
	교재 p168 ~ 170

	객체를 생성하고 객체의 멤버변수 초기화를 목적으로
	InitMembers라는 이름의 함수를 정의하고 호출하였다

	정보은닉을 목적으로 private 선언했으니 어쩔 수 없는 일이다
	그러나 이는 여간 불편한게 아니다

	이러한 문제를 해결해주는게 생성자이다
	생성자를 이용하면 객체 생성과 동시에 초기화할 수 있게 한다

	생성자는 클래스의 이름과 함수의 이름이 동일하다
	반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다

	이러한 유형의 함수를 가리켜 생성자(constructor)라 한다
	그리고 생성자는 객체 생성시 딱 한번 호출된다

	생성자도 함수의 일종이니 오버로딩 할 수 있고,
	매개변수에 디폴트 값을 설정할 수 있다
*/

#include <iostream>

using namespace std;

class SimpleClass
{

private:
	int num1;
	int num2;

public:
#if !first
	SimpleClass()
	{

		num1 = 0;
		num2 = 0;
	}

	SimpleClass(int n)
	{

		num1 = n;
		num2 = 0;
	}

	SimpleClass(int n1, int n2)
	{

		num1 = n1;
		num2 = n2;
	}
#else

	// 생성자를 결정하지 못해 발생하는 에러 방지를 위해
	// 조건부 컴파일을 했다
	SimpleClass(int n1 = 0, int n2 = 0)
	{

		num1 = n1;
		num2 = n2;
	}
#endif
	void ShowData() const
	{

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{

	// 1개짜리는 소괄호가 필요없다
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	return 0;
}