/*
��¥ : 2024. 6. 20
�̸� : �輺��
���� : new & delete
	���� p92 ~ 93

	C++������ new & delete Ű���带 �����Ѵ�
	new�� �̿��ϸ� �Ҵ��� ����� ������ ����Ʈ ũ������� ������ �ʿ䰡 ���� ����ȯ�� �ʿ����
	�׸��� ������ ���� delete�� �̿��� �����ϸ� �ȴ�
	delete�� ��� �迭�� ���¸� ���� �տ� []�� �ٿ� �߰��� ������ֱ⸸ �ϸ� �ȴ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* MakeStrAdr(int _len)
{

	// char* str = (char*)malloc(sizeof(char) * _len);
 	char* str = new char[_len];
	return str;
}

int main(void)
{

	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// free(str);
	delete[] str;
	return 0;
}