/*
��¥ : 2023. 2. 15
�̸� : �輺��
���� : ���� ������
	����Ʈ ���� �������� ������
	
	��� �� ����� ���簡 �̷����� ���� ���鼭 C��� ����ü ������ ���Կ����� ����� ����ϴٰ� �����ϱ� ����
	�׷��� ��ü���� ���Կ����� C����� ����ü �������� ���Կ���� ���������� �ٸ���
	�̴� �ܼ��� ���Կ����� �ƴ�, ���Կ����ڸ� �����ε� �� �Լ��� ȣ���̱� �����̴�
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

		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	/*
	// ������ ���� ����
	Person& operator=(Person& ref) {

		delete[] name;	// ������ ���� name�� ������ �� ���� 
						// �޸� ������ �߻�
		int lne = strlen(ref.name) + 1;
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
	*/

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);

	man2 = man1;

	// ���� ���� ��� ��ȯ
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
// �ٸ� �Ҹ��ڴ� 1���� ȣ��ǰ� vs���� ������ ���� �߻�