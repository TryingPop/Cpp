/*
��¥ : 2023. 2. 15
�̸� : �輺��
���� : �迭
	C, C++�� �⺻ �迭�� Ư¡
		��� �˻縦 ���� �ʴ´�
*/

#include <iostream>
using namespace std;

int main(void)
{

	int arr[3] = { 1, 2, 3 };
	// ��� �˻縦 ���� �ʾ� ������ ���� Ư���� ����
	// �� �� �����Ⱚ�� ȣ���Ѵ�
	cout << arr[-1] << endl;	// arr�� �ּ� sizeof(int) * -1�� ��ġ�� ����
	cout << arr[-2] << endl;	// arr�� �ּ� sizeof(int) * -2�� ��ġ�� ����
	return 0;
}