/*
��¥ : 2023. 1. 23
�̸� : �輺��
���� : �����ڸ� ��ȯ�ϴ� �Լ�
	�����ڸ� ��ȯ�ϴ� �Լ� ����
*/

#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{

	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref) {

	ref++;
	return ref;
}

int& RefRetFuncThree(int ref) {

	ref++;
	return ref;
}

int main(void) 
{

	int num1 = 1;						
	int& num2 = RefRetFuncOne(num1);	 
	// �����ڰ� �ƴ϶� �� �ּ� �Ҵ� �ް� ���� �޾ƿ�
	int num3 = RefRetFuncOne(num1);	
	int num4 = RefRetFuncTwo(num1);
	// int& num5 = RefRetFuncTwo(num1);		// ���� �ȸ¾Ƽ� ���� �Ұ���
	int& num6 = RefRetFuncThree(num1);		// �����ϴ� ������ �ݹ� �����Ǵ� ���������� �̻��� ��� ����� ���δ�

	// num1 = num2 = num4 = 4, num3 = 3�� ����
	num1++;
	num2++;
	// ������� num3�� num4�� ���� �ȹ����Ƿ� num3 = 3, num4 = 4
	num3++;
	num4++;
	num6++;

	cout << "num1 : " << num1 << endl;	// 6
	cout << "num2 : " << num2 << endl;	// 6
	cout << "num3 : " << num3 << endl;	// 4
	cout << "num4 : " << num4 << endl;	// 5
	cout << "num6 : " << num6 << endl;	// ??? ������ �� ���� �� ���
	return 0;
}