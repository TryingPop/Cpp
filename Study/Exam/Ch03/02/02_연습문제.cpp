/*
��¥ : 2023. 1. 26
�̸� : �輺��
���� : ���� 135p ����2
	���ڿ� ������ ���ο� �����ϴ� Printer��� �̸��� Ŭ������ ����������.
	�� Ŭ������ �� ���� ����� ������ ����
		- ���ڿ� ����
		- ���ڿ� ���

	�Ʒ��� main �Լ��� ������ ���� �����ϴ� Printer Ŭ������ �����ϵ�,
	�̹����� ���� ��������� private����, ����Լ��� public���� ��������.
	int main(void)
	{
		Printer pnt;
		pnt.SetString("Hello world!");
		pnt.ShowString();

		pnt.SetString("I love C++");
		pnt.ShowString();
		return 0;
	}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// malloc�� �̿��� �����غ���
class Printer {

private:
	// char* savedStr;
	char savedStr[20];

public:
	void SetString(const char* inputStr) {
		/*
		// �����ϴ� �ڵ带 ������ �ϴµ� �𸣰ڴ�
		savedStr = (char*)malloc(sizeof(inputStr));
		strcpy(savedStr, inputStr);
		*/
		
		strcpy(savedStr, inputStr);
	};

	void ShowString() {

		cout << savedStr << endl;
		// free(savedStr);
	};
};

int main(void) 
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}