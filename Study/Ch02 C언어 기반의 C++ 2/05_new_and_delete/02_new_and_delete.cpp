/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : new & delete
	malloc�� ���� �����ϰ� �����Ǵ� new
*/
#define _CRT_SECURE_NO_WARNINGS		// strcpy ��������

#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

char* MakeStrAdr(int len) {

	char* str = new char[len];
	return str;
}

int main(void) 
{

	char* str = MakeStrAdr(20);

	strcpy(str, "I am so happy~");
	cout << str << endl;

	// �迭�� �����ϴ� ��� delete�ڿ� []�� �߰�������Ѵ�
	delete[] str;
	return 0;
}