/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : 이니셜라이저를 이용한 참조자 선언
	교재 p183 ~ 184

	const 변수와 마찬가지로 참조자도 선언과 동시에 초기화가 이뤄져야 한다
	이니셜라이저를 이용하면 참조자도 멤버변수로 선언될 수 있다

	참조자를 멤버변수로 선언하는 경우가 흔한 것은 아니다
*/

#include <iostream>

using namespace std;

class AAA
{

public:
	AAA()
	{

		cout << "empty object" << endl;
	}

	void ShowYourName()
	{

		cout << "I'm class AAA" << endl;
	}
};

class BBB
{

private:
	AAA& ref;
	const int& num;

public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{ 
		
		// Empty constructor body 
	}

	void ShowYourName()
	{

		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void)
{

	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();

	return 0;
}