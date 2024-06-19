/*
��¥ : 2024. 6. 19
�̸� : �輺��
���� : Call by address? Call by reference!
	���� p76 ~ 79

	Call by reference ������ �Լ�ȣ����
	Call by address�� �Ҹ��� ��츦 ���� ����

	C++�� ������(reference) ����� �Լ�ȣ��� ������ �����ε�
	�ּ� ���� �����ϴ� �Լ��� ȣ�����¸� ������ ������ Call by reference�� ǥ���Ѵ�

		int* SimpleFunc(int* _ptr);
	��ó�� ����� �Լ��� Call by value ���� Call by reference ������ �Լ� ���Ǹ� �����Ѵ�
	����
		int* SimpleFunc(int* _ptr)
		{

			return _ptr + 1;
		}

	�� ���ǵǾ��� �ִٸ� Call by reference�� ���ٴ� Call by value�� ���� ���� �Ǵ�
	�Լ��� ���� ��ü�� ��(value)�ε�, �� ���� �ּ� ���� ���̴�
	int���̴� 4�� ������ �ּ� ���� �ȴ�

	�ּ� ���� �̿��ؼ� �Լ� �ܺο� ����� ������ �����ϴ� Call by reference�ʹ� �Ÿ��� �ִ�
	�ݸ� ����ó�� ���ǵǸ� Call by reference�̴�
		int* SimpleFunc(int* _ptr)
		{

			if (_ptr == NULL) return NULL;
			
			*_ptr = 20;
			return _ptr;
		}

	�� �Լ������� �ּ� ���� �̿��ؼ� �Լ� �ܺο� ����� ������ ����(reference) ������,
	�̴� �и��� Call by reference�̴�

	���� C���� ���ϴ� Call by reference�� ������ �ǹ̸� ���Ѵ�
	�ּ� ���� ���޹޾Ƽ�, �Լ� �ܺο� ����� ������ �����ϴ� ������ �Լ� ȣ��

	�� �ּ� ���� �ܺ� ������ ���������� ���Ǵ� �Լ��� ȣ���� ���Ѵ�
	�ּ� ���� ���޵� ����� �߿��Ѱ� �ƴ϶�, 
	�ּ� ���� ������ ������ ���Ǿ��ٴ� ��ø� �߿��� ���̴�

	C++������ �� ���� ������� Call by reference �Լ����ǰ� �����ϴ�
	void SwapByRef2(int& _ref1, int& _ref2)
	{

		int temp = _ref1;
		_ref1 = _ref2;
		_ref2 = temp;
		// Call by reference
	}

	�����ڴ� ����� ���ÿ� ������ �ʱ�ȭ�Ǿ���Ѵ�
	�Ű������� �Լ��� ȣ��Ǿ�� �ʱ�ȭ�� ����Ǵ� �������̴�
	�׷��� �� �Ű����� ������ �ʱ�ȭ�� �̷����� ���� ���� �ƴ϶�,
	�Լ�ȣ�� �� ���޵Ǵ� ���ڷ� �ʱ�ȭ�� �ϰڴٴ� �ǹ��� �����̴�

	��ó�� C++���� Call by reference�� ��������� �����ڸ� �̿��ϴ� �����
	�ּ� ���� �̿��ϴ� ���, �̷��� �� ������ �����Ѵ�
*/

#include <iostream>

using namespace std;

void SwapByRef2(int& _ref1, int& _ref2)
{

	int temp = _ref1;
	_ref1 = _ref2;
	_ref2 = temp;
}

int main(void) 
{

	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	
	return 0;
}