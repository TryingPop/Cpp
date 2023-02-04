/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 상속의 방법과 결과
	클래스 B가 클래스 A를 상속받으면,
	클래스 B는 클래스 A의 모든 멤버를 물려받는다

	즉 클래스 B 객체에는 B 클래스에 선언되어 있는 멤버뿐만 아니라 
	클래스 A에 선언되어 있는 멤버도 존재한다

	클래스 A를 부모 클래스, 클래스 B를 자식 클래스라 한다

	자식 클래스의 생성자는 부모 클래스의 멤버까지 초기화 해야한다
	또한, 생성자는 부모 클래스의 생성자를 호출해서 부모 클래스의 멤버를 초기화하는 것이 좋다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {

private:
	int age;		// 나이
	char name[50];	// 이름

public:
	Person(int myage, const char* myname) 
		: age(myage) {

		strcpy(name, myname);
	}

	void WhatYourName() const {

		cout << "My name is " << name << endl;
	}

	void HowOldAreYou() const {

		cout << "I am " << age << " years old" << endl;
	}
};

class UnivStudent : public Person {	// Person 클래스의 상속을 의미함
									
private:
	char major[50];	// 전공 과목

public:
	UnivStudent(const char* myname, int myage, const char* mymajor)
		: Person(myage, myname) {

		strcpy(major, mymajor);
	}

	void WhoAreYou() const {

		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{

	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}