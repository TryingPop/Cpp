/*
날짜 : 2023. 2. 6
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
	MyFriendInfo(const char* name, int age)
		: age(age) {

		cout << "MyFriendInfo construct" << endl;

		this->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		strcpy(this->name, name);
	}

	void ShowMyFriendInfo() {

		cout << "이름 : " << name << endl;;
		cout << "나이 : " << age << endl;
	}

	~MyFriendInfo() {

		free(name);

		cout << "MyFriendInfo destruct" << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {

private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone) 
		: MyFriendInfo(name, age) {

		cout << "MyFriendDetailInfo construct" << endl;

		this->addr = (char*)malloc(sizeof(char) * (strlen(addr) + 1));
		this->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));

		strcpy(this->addr, addr);
		strcpy(this->phone, phone);
	}

	void ShowMyFriendDetailInfo() {

		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}

	~MyFriendDetailInfo() {

		free(addr);
		free(phone);

		cout << "MyFriendDetailInfo destruct" << endl;
	}
};

int main(void)
{

	MyFriendDetailInfo mfdi("비둘기", 1, "한국", "010-1234-5678");
	return 0;
}