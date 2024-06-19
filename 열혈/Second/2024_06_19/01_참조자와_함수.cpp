/*
��¥ : 2024. 6. 19
�̸� : �輺��
���� : �����ڿ� �Լ�
	���� p74 ~ 76

	������ �����ڸ� �Բ� �����ϴ� ���� ����
	�������� �н��� ���� �ڵ忴��
	�������� Ȱ�뿡�� �Լ��� ū ��ġ�� �����Ѵ�
	���� �Լ��� �������� ���踦 ����

	�տ��� Call by value & Call by reference �Լ� ȣ������ �־���
	Call by value�� ���� ���ڷ� �����ϴ� �Լ��� ȣ�����̿���,
	Call by reference�� �ּ� ���� ���ڷ� �����ϴ� �Լ��� ȣ������ ����

	Call by value�� ���·� ���ǵ� �Լ��� ���ο�����
	�Լ��ܺο� ����� ������ ������ �Ұ����ϴ�

	���� �� ������ ����� ���� ���� �ٲ㼭 ������ �������� 
	������ ���� �Լ��� �����ϸ� ���ϴ� ����� ���� �� ����
		void SwapByValue(int _num1, int _num2)
		{

			int temp = _num1;
			_num1 = _num2;
			_num2 = temp;
			// Call by value
		}

	�ش� �Լ��� main �Լ����� �����ϸ� ��ȭ�� ������ �� �� �ִ�
	�׷��� �ʿ��� ���� ������ ���� Call by reference ����� �Լ��̴�
		void SwapByRef(int* _ptr1, int* _ptr2)
		{

			int temp = *_ptr1;
			*_ptr1 = *_ptr2;
			*_ptr2 = temp;
			// Call by reference
		}
	
	�� �Լ��� �� ���� �ּ� ���� �޾Ƽ�,
	�� �ּ� ���� �����ϴ� ������ ����� ����
	���� �����ϰ� �ִ�
	���� �� �Լ��� ������� ������ main �Լ��� �����ϸ�
	������� Ȯ���� �� �ִ�
*/

#include <iostream>
#define endl '\n'

using namespace std;

void SwapByValue(int _num1, int _num2)
{

	int temp = _num1;
	_num1 = _num2;
	_num2 = temp;
	// Call by value
}

void SwapByRef(int* _ptr1, int* _ptr2)
{

	int temp = *_ptr1;
	*_ptr1 = *_ptr2;
	*_ptr2 = temp;
	// Call by reference
}

int main(void)
{

	int val1 = 10, val2 = 20;

	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 10, 20

	SwapByValue(val1, val2);
	cout << "SwapByValue" << endl;
	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 10, 20

	SwapByRef(&val1, &val2);
	cout << "SwapByRef" << endl;
	cout << "val1, val2: " << val1 << ", " << val2 << endl;		// 20, 10

	return 0;
}