/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : C����� �� ��ȯ
	C����� �� ��ȯ �������� ���� �ȵǴ� ����

	static_cast �����ڴ� �Ʒ��� �� ��ȯ�� ���� ���Ѵ�
*/

#include <iostream>
using namespace std;

int main(void)
{

	const int num = 20;
	
	int* ptr = (int*)& num;		// const ����� ������ (const ������)�̹Ƿ� �� ��ȯ�� �ߴ�
	// const int* ptr = &num;	
	*ptr = 30;					// int* �� �� ��ȯ�� �ؼ� �� ������ ���� 
								// const int* ptr�� �ϸ� ������ ������ ���

	cout << *ptr << endl;		// 30
	// cout << num << endl;		// 20

	float* adr = (float*)ptr;	
	cout << *adr << endl;		// ����� �����͸� float������ �ؼ��ؼ� ����Ѵ�
	return 0;
}