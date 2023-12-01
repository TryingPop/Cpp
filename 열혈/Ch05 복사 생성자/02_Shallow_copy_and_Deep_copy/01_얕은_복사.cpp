/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���� ����
	�տ����� ����� ���� �����̴�
	���� ������ ������ ����
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

		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
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

// �޸� �������� man1 �Ǵ� man2�� name�� ���� �Ǿ��µ� 
// ���� Ŭ�������� delete[] name�� �����ϴµ� 
// delete �ϰ��� �ϴ� ����� �̹� ��� ������ �߰� �ȴ�