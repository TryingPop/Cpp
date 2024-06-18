/*
��¥ : 2024. 6. 18
�̸� : �輺��
���� : C����� ���� (ȣ�� ����)
	���� p62 ~ 63

	�Լ��� ȣ�����´� ũ�� ���� ���� ȣ��(Call by value)��
	������ ���� ȣ��(Call by reference)�� ������

	�� ���� ������ ������ ��������, �� int�� ������ ���� ��ȯ�ϴ�
	Swap �Լ��� ���� ���鼭 �����غ���

	Call by value�� �ش� ���� �״�� �����ϴ� ���̰�,
	Call by reference�� ������ ����Ű�� �ּҸ� �����ϴ� ���� �ǹ��Ѵ�

	�׷��� Call by value�� ������ ������
	���� �����ص� ���� ���� ������ ��ġ�� �ʴ´�

	�ݸ� Call by reference�� ������ ������
	�ּҸ� �����߱⿡ �ּҿ� �ִ� ���� ���������� ������ ����������
	�̿� �ش� �ּ��� ���� �ٲٸ� �Լ��� ������ ��ȯ�� ä�� �ִ´�
*/

#include <iostream>

#define endl '\n'
#define AND ", "
using namespace std;

void SwapValue(int _num1, int _num2)
{

	int temp = _num1;
	_num1 = _num2;
	_num2 = temp;
}

void SwapRef(int* _num1, int* _num2)
{

	int temp = *_num1;
	*_num1 = *_num2;
	*_num2 = temp;
}

int main(void)
{

	int num1 = 10, num2 = 20;

	cout << "Before ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 10 20

	// �Ű����� _num1, _num2�� ���� �ٲ��
	// num1, num2�� �ٲ��� �ʴ´�
	SwapValue(num1, num2);
	cout << "SwapValue ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 10 20

	// num1, num2 �ּҰ� ���޵Ǿ�
	// �ּҰ� ����Ű�� ���� ����ȴ�
	// �׷��� num1�� ����, num2�� ����Ű�� ���� �ڹٲ��
	SwapRef(&num1, &num2);
	cout << "SwapRef ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 20 10


	return 0;
}