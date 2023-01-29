/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : 객체 포인터 배열
	앞의 예제를 변경해 객체 포인터 배열 생성 방법 예제
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

		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << endl;
	}

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person* parr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++) {

		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	// (*(parr[0])).ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}