/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : const
	��ġ�� ���� const�� �ǹ̸� �˾ƺ���
*/

#include <iostream>
using namespace std;

int main(void)
{
	
	int val1 = 1;
	int val2 = 2;
	
	// int* num1�� ���
	const int* num1 = &val1;

	num1 = &val2;				// num1�� �ּҰ� val2�� �ּҷ� �ٲ��
	// *num1 = 20;				// ������ num1�� ���� ���� ���� val1�� �����ϴ°� �ȵȴ�

	// num2�� ���ȭ
	int* const num2 = &val1;

	//num2 = &val2;				// num2�� ����̹Ƿ� �ٸ� ������ �ּҷ� ���ٲ۴�
	*num2 = 5;					// �ݸ� num2�� ���� ��ȯ���� val2�� ���� ��ȯ�� �� �ִ�.

	const int* const num3 = &val1;
	// ���� ���� �����ؼ� ���� num3�� �� ���浵 �ȵǰ� �ּҵ� ���ٲ۴�
	
	// �Ʒ� �� ���� ���̰� ����
	const int num4 = 4;
	int const num5 = 5;

	// �ݸ� val1�� �̻���� �� ���� �����ϴ�
	val1 = val2;
}