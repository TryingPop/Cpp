/*
��¥ : 2024. 7. 8
�̸� : �輺��
���� : ��ü �迭
	���� p191 ~ 194

	C���� ����ü �迭�� �����غ����� �ִ�
	���������� ����ü ������ �迭�� �����غ��� �ִ�

	��ü �迭 �� ��ü ������ �迭�� �̿� �����ϴ�

	(Ŭ���� ��)*  (�迭 ���� �̸�) = new (Ŭ������)[(�迭�� ����)];
	���·� ���𰡴��ϴ�
	
	����ü �迭�� ����� ���̰� ����
	��ó�� ��ü �迭�� �����ϴ� ��쿡�� �����ڴ� ȣ��ȴ�
	��, �迭�� ������������� ȣ���� �����ڸ� ������ ������� ���Ѵ�
	(�����ڿ� ���ڸ� �������� ���Ѵ�)

	�׷��� �ݵ�� void�� �����ڰ� ���ǵǾ� �־�� �Ѵ�
		(Ŭ���� ��)() { ... }
	������ �����ڰ� ���ǵǾ�� �Ѵ�

	���ϴ� ������ �ʱ�ȭ �Ѵٸ�
	������ �ʱ�ȭ�� ������ ������ ���ľ� �Ѵ�

	�Ʒ� ������ �����غ���
	��ü �迭 ���� �� void�� �����ڰ� ȣ����� Ȯ���� �� �ִ�
	�׸��� �迭 �Ҹ�ÿ��� �� �迭�� �����ϴ� ��ü�� �Ҹ��ڰ� ȣ����� Ȯ���� �� �ִ�
*/

#include <iostream>
#include <cstring>

using namespace std;

class Person
{

private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{

		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}

	Person()
	{

		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)
	{

		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{

		cout << "�̸�: " << name << ", ";
		cout << "����: " << age << endl;
	}

	~Person() 
	{

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

	for (int i = 0; i < 3; i++)
	{

		cout << "�̸�: ";
		cin >> namestr;

		cout << "����: ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];

		strcpy_s(strptr, len, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();

	return 0;
}