#include <iostream>
// ��ũ�� �Լ�
#define SQUARE(x) ((x) * (x))
using namespace std;

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �ζ��� �Լ��� ��ũ�� �Լ�
	��ũ�� �Լ� : �Ϲ� �Լ��� ���� �ӵ��� ������ 
			�ݸ� ������ �Լ��� ��ũ���� ���·� �����ϴµ� �Ѱ谡 �ִ�
	�ζ��� �Լ� : ��ũ�� �Լ��� ������ ������ C++�� �Լ�
	
	��ũ�� �Լ��� �ڷ����� ������� ��밡���ϴ�
	�ζ��� �Լ��� ���ø��� �̿��� �ڷ��� ������� �̿� ����

	���ø��� ������ ���� �̿� ���� ���Ŀ� �ٷ��
	template <typename T>
	inline  T Add(T num1, T num2) {

		return num1 + num2;
	}
*/

inline int Add(int num1, int num2) {

	return num1 + num2;
}




int main()
{
	cout << "��ũ�� �Լ� SQUARE(1) : " << SQUARE(1) << endl;
	cout << "�ζ��� �Լ� Add(1, 1) : " << Add(1, 1) << endl;

	return 0;
}