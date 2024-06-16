/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 소멸자
	객체소멸 시 반드시 호출되는 것은 소멸자

	형식은
	~클래스명() { 실행할 코드 }
	반환형이 선언되어 있지 않으며,
	실제로 반환하지 않는다
	
	매개변수는 void형으로 선언되어야 하기 때문에 오버로딩도, 
	디폴트 값 설정도 불가능하다

	소멸자는 대개 생성자에서 할당한 리소스의 소멸에 사용된다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {

private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage) {

		int len = strlen(myname) + 1; // 문자열 끝 값 때문에 1칸 더 크게 잡는다
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {

		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void) 
{
	
	Person man1("Lee Dong Woo", 29);
	Person man2("Jang dong gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}