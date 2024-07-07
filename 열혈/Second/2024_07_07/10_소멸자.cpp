/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : 소멸자의 이해와 활용
	교재 p187 ~ 190

	객체생성시 반드시 호출되는 것이 생성자라면,
	객체소멸시 반드시 호출되는 것은 소멸자이다
	소멸자는 클래스의 이름 앞에 ~ 가 붙은 형태의 이름을 갖는다
	반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다
	매개변수는 void 형으로 선언되어야 하기 때문에 오버로딩도, 디폴트 값 설정도 불가능하다

	소멸자는 객체소멸 과정에서 자동으로 호출이 된다
	프로그래머가 직접 소멸자를 정의하지 않으면
	디폴트 생성자와 마찬가지로 아무런 일도 하지 않는 디폴트 소멸자가 자동으로 삽입된다

	소멸자는 대개 생성자에서 할당한 리소스의 소멸에 사용된다
	new 연산자를 이용해서 할당해 놓은 메모리 공간이 ㅣㅆ다면,
	소멸자에서는 delete 연산자를 이용해서 메모리 공간을 소멸한다
*/

#include <iostream>
#include <cstring>

using namespace std;

class Person
{

private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{

		int len = strlen(myname) + 1;
		name = new char[len];
		// len 만큼만 복사를 한다
		strcpy_s(name, len, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{

		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person()
	{

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}