#include <iostream>
using namespace std;

/*

��¥ : 2023. 1. 22
�̸� : �輺��
���� : �Լ��� �����ε�
	�Լ��� �Ű����� ������ ���� �Լ��� ã�Ƽ� ������ ���
*/

// �����ε��� �Լ��� ���� 
void MyFunc(void) {

	cout << "MyFunc(void) called" << endl;
}

void MyFunc(char c) {

	cout << "MyFunc(char c) called" << endl;
}

void MyFunc(int a, int b) {

	cout << "MyFunc(int a, int b) called" << endl;
}

int main() 
{

	// �����ε� ��� Ȯ��
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}