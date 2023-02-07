/*
날짜 : 2023. 2. 7
이름 : 배성훈
내용 : 교재 296p 문제2
	다음 두 클래스에 적절한 생성자와 소멸자를 정의해보자.
	그리고 이의 확인을 위한 main 함수를 정의해 보자.
	class MyFriendInfo {
	private:
		char* name;
		int age;
	public:
		void ShowMyFriendInfo() {
			cout << "이름 : " << name << endl;
			cout << "나이 : " << age << endl;
		}
	};
	class MyFriendDetailInfo : public MyFriendInfo {
	private:
		char* addr;
		char* phone;
	public:
		void ShowMyFriendDetailInfo() {
			ShowMyFriendInfo();
			cout << "주소 : " << addr << endl;
			cout << "전화 : " << phone << endl;
		}
	};
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {

private:
	char* name;
	int age;

public:
	MyFriendInfo(const char* fname, int fage)
		: age(fage) {

		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}

	void ShowMyFriendInfo() {

		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~MyFriendInfo() {

		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {

private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(const char* fname, int fage, const char* adr, const char* pnum)
		: MyFriendInfo(fname, fage) {

		addr = new char[strlen(adr) + 1];
		phone = new char[strlen(pnum) + 1];

		strcpy(addr, adr);
		strcpy(phone, pnum);
	}

	void ShowMyFriendDetailInfo() {

		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}

	~MyFriendDetailInfo() {

		delete[] addr;
		delete[] phone;
	}
};

int main(void)
{

	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-1234-00XX");
	MyFriendDetailInfo fren2("이주성", 19, "경기 인천", "010-3333-00XX");

	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();
	return 0;
}