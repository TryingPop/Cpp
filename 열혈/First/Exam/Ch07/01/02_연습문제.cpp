/*
��¥ : 2023. 2. 6
�̸� : �輺��
���� : ���� 296p ����2
	���� �� Ŭ������ ������ �����ڿ� �Ҹ��ڸ� �����غ���.
	�׸��� ���� Ȯ���� ���� main �Լ��� ������ ����.

	class MyFriendInfo {

	private:
		char* name;
		int age;

	public:
		void ShowMyFriendInfo() {

			cout << "�̸� : " << name << endl;
			cout << "���� : " << age << endl;
		}
	};

	class MyFriendDetailInfo : public MyFriendInfo {

	private:
		char* addr;
		char* phone;

	public:
		void ShowMyFriendDetailInfo() {

			ShowMyFriendInfo();
			cout << "�ּ� : " << addr << endl;
			cout << "��ȭ : " << phone << endl;
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

		cout << "�̸� : " << name << endl;;
		cout << "���� : " << age << endl;
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
		cout << "�ּ� : " << addr << endl;
		cout << "��ȭ : " << phone << endl;
	}

	~MyFriendDetailInfo() {

		free(addr);
		free(phone);

		cout << "MyFriendDetailInfo destruct" << endl;
	}
};

int main(void)
{

	MyFriendDetailInfo mfdi("��ѱ�", 1, "�ѱ�", "010-1234-5678");
	return 0;
}