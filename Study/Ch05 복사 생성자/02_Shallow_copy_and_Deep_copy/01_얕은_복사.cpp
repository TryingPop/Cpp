/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 얕은 복사
	앞에서의 복사는 얕은 복사이다
	얕은 복사의 문제점 예제
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

// 메모리 해제에서 man1 또는 man2의 name이 해제 되었는데 
// 남은 클래스에서 delete[] name을 수행하는데 
// delete 하고자 하는 대상이 이미 없어서 에러가 뜨게 된다