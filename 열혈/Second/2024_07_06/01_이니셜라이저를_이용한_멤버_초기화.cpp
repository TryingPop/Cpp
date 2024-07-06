/*
날짜 : 2024. 7. 6
이름 : 배성훈
내용 : 멤버 이니셜라이저(Member Initializer)를 이용한 멤버 초기화
	교재 p175 ~ 176

	객체를 생성하는 과정에서 클래스의 생성자를 이용해 객체를 초기화할 수 있다
	생성자는 초기화를 목적으로 정의가 되니,
	객체 생성과정에서의 생성자 호출은 객체의 초기화를 한결 수월하게 한다
	이는 이니셜 라이저라는 것을 이용하면 된다

	아래 예제로 보자
	객체 a의 생성과정에서 _anum1, _anum2를 인자로 전달받는 생성자를 호출하고
	객체 b의 생성과정에서 _bnum1, _bnum2를 인자로 전달받는 생성자를 호출하라는 의미이다
*/

class A
{

private:
	int num1;
	int num2;

public:
	A(const int& _num1, const int& _num2)
	{

		num1 = _num1;
		num2 = _num2;
	}
};

class AA
{

private:
	A a;
	A b;

public:
	AA(const int& _anum1, const int& _anum2, const int& _bnum1, const int& _bnum2)
		// 멤버 이니셜라이저
		: a(_anum1, _anum2), b(_bnum1, _bnum2)
	{ }
};