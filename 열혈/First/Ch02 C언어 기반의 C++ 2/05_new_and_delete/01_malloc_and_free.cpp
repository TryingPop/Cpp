/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : malloc & free
	C���� ����ϴ� ���� �޸� �Ҵ�
*/
#define _CRT_SECURE_NO_WARNINGS		// strcpy ��������

#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

/// <summary>
/// ���ڿ� ���� �޸� �Ҵ�
/// 1(char�� ũ��) * len ����Ʈ��ŭ �Ҵ��Ѵ�
/// </summary>
/// <param name="len">���ڿ��� ����</param>
/// <returns>�Ҵ�� �޸��� �ּ�</returns>
char* MakeStrAdr(int len) {

	char* str = (char*)malloc(sizeof(char) * len);	
	return str;
}

int main(void) {

	// str �����Ϳ� 20 ����Ʈ �޸� �Ҵ�
	char* str = MakeStrAdr(20);

	// str�� I am so happy~ ���ڿ��� ������ �ִ´�
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// str �޸� ����
	free(str);
	return 0;
}