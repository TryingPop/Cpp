/*
��¥ : 2024. 6. 20
�̸� : �輺��
���� : new & delete
	���� p91 ~ 92

	C�� �����ϸ鼭 malloc�� free �Լ��� �ʿ伺�� �����ϴ� ���� �ϳ��� ��� �� �� �ִ�
	���� �޸� �Ҵ� �� �Ҹ꿡 �ʿ��� �Լ��� malloc�� free�̴�

	���������� ���ڷ� �޾Ƽ�, �ش� ������ ���ڿ� ������ ������ �迭�� �����ϰ�,
	�� �迭�� �ּ� ���� ��ȯ�ϴ� �Լ��� �����غ���

	�Ʒ��� ���� �� ���� ��������� ������
		�Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ� �Ѵ�
		��ȯ���� void�� �������̱� ������ ������ �� ��ȯ�� ���ľ� �Ѵ�

	C++���� �����ϴ� Ű���� new�� delete�� ����ϸ� �̷��� ������ ���� �������
	new�� malloc �Լ��� ����ϴ� Ű�����̰�,
	delete�� free �Լ��� ����ϴ� Ű�����̴�
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char* MakeStrAdr(int _len)
{

	char* str = (char*)malloc(sizeof(char) * _len);
	return str;
}

int main(void)
{

	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	free(str);
	return 0;
}