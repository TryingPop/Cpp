/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 깊은 복사
	앞의 예제를 깊은 복사로 복사하기

	멤버 변수에 할당하는 값을 새로이 만드는 것?
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

		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	Person(Person& copy)
		: age(copy.age) {
		int len = strlen(copy.name) + 1;
		name = (char*)malloc(sizeof(char) * len);
		strcpy(name, copy.name);
	}

	void ShowPersonInfo() const {

		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void) 
{

	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}