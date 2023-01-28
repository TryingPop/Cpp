/*
��¥ : 2023. 1. 28
�̸� : �輺��
���� : �Ҹ���
	��ü�Ҹ� �� �ݵ�� ȣ��Ǵ� ���� �Ҹ���

	������
	~Ŭ������() { ������ �ڵ� }
	��ȯ���� ����Ǿ� ���� ������,
	������ ��ȯ���� �ʴ´�
	
	�Ű������� void������ ����Ǿ�� �ϱ� ������ �����ε���, 
	����Ʈ �� ������ �Ұ����ϴ�

	�Ҹ��ڴ� �밳 �����ڿ��� �Ҵ��� ���ҽ��� �Ҹ꿡 ���ȴ�
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

		int len = strlen(myname) + 1; // ���ڿ� �� �� ������ 1ĭ �� ũ�� ��´�
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {

		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void) 
{
	
	Person man1("Lee Dong Woo", 29);
	Person man2("Jang dong gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}