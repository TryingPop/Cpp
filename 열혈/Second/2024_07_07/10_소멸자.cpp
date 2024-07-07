/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : �Ҹ����� ���ؿ� Ȱ��
	���� p187 ~ 190

	��ü������ �ݵ�� ȣ��Ǵ� ���� �����ڶ��,
	��ü�Ҹ�� �ݵ�� ȣ��Ǵ� ���� �Ҹ����̴�
	�Ҹ��ڴ� Ŭ������ �̸� �տ� ~ �� ���� ������ �̸��� ���´�
	��ȯ���� ����Ǿ� ���� ������, ������ ��ȯ���� �ʴ´�
	�Ű������� void ������ ����Ǿ�� �ϱ� ������ �����ε���, ����Ʈ �� ������ �Ұ����ϴ�

	�Ҹ��ڴ� ��ü�Ҹ� �������� �ڵ����� ȣ���� �ȴ�
	���α׷��Ӱ� ���� �Ҹ��ڸ� �������� ������
	����Ʈ �����ڿ� ���������� �ƹ��� �ϵ� ���� �ʴ� ����Ʈ �Ҹ��ڰ� �ڵ����� ���Եȴ�

	�Ҹ��ڴ� �밳 �����ڿ��� �Ҵ��� ���ҽ��� �Ҹ꿡 ���ȴ�
	new �����ڸ� �̿��ؼ� �Ҵ��� ���� �޸� ������ �Ӥ��ٸ�,
	�Ҹ��ڿ����� delete �����ڸ� �̿��ؼ� �޸� ������ �Ҹ��Ѵ�
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
		// len ��ŭ�� ���縦 �Ѵ�
		strcpy_s(name, len, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{

		cout << "�̸�: " << name << endl;
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

	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}