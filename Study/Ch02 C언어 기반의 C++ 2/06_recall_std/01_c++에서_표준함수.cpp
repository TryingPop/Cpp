/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : C++���� ǥ���Լ� ȣ��
	math.h >> cmath
	stdio.h >> cstdio
	string.h >> cstring
	�� ���� ����ϱ�

	����
		���� ������ ȣȯ���� �������ش�

	������
		��� ǥ���Լ����� �̸����� std�� ���ǵǾ��� �ִ�
*/

#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

int main(void) 
{

	char str1[] = "Result";
	char str2[30];

	strcpy_s(str2, str1);
	printf("%s : %f \n", str1, sin(0.14));
	printf("%s : %f \n", str2, abs(-1.25));
	return 0;
}