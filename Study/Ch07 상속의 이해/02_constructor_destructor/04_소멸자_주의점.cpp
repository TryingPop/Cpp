/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 소멸자 정의 시 주의점
	생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제해야한다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {

private:
	char* name;

public:
	Person(const char* myname) {

		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}

	~Person() {

		delete[] name;
	}

	void WhatYourName() const {

		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person {

private:
	char* major;

public:
	UnivStudent(const char* myname, const char* mymajor) 
		: Person(myname) {

		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}

	~UnivStudent() {

		delete[] major;
	}

	void WhoAreYou() const {

		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{

	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();

	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}