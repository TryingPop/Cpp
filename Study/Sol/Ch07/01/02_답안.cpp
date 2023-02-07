/*
��¥ : 2023. 2. 7
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
	MyFriendInfo(const char* fname, int fage)
		: age(fage) {

		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}

	void ShowMyFriendInfo() {

		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
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
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;
	}

	~MyFriendDetailInfo() {

		delete[] addr;
		delete[] phone;
	}
};

int main(void)
{

	MyFriendDetailInfo fren1("������", 22, "�泲 �ƻ�", "010-1234-00XX");
	MyFriendDetailInfo fren2("���ּ�", 19, "��� ��õ", "010-3333-00XX");

	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();
	return 0;
}