/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : 객체 배열
	객체 기반의 배열은 다음형태로 선언한다
	클래스명 변수명[크기]
	클래스명* 변수명 = new 클래스명[크기];

	배열의 선언과정에서는 호출할 생성자를 별도로 명시하지 못한다
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
	Person(char* myname, int myage) {

		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	Person() {

		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage) {

		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const {

		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person parr[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++) {

		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}
