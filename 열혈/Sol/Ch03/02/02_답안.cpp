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

class Printer {

private:
	char str[30];
public:
	// void SetString(char* s);		// const �ȳ־��ָ� ���� ���
	void SetString(const char* s);
	void ShowString();
};

//void Printer::SetString(char* s) {
void Printer::SetString(const char* s) {

	strcpy(str, s);
}

void Printer::ShowString() {

	cout << str << endl;
}

int main(void) 
{

	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}