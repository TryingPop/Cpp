/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : ����Ʈ ���� �Լ��� ����κп����� ǥ���ϸ� �ȴ�
	���� p29

	����Ʈ ���� �Լ��� ����κп����� ǥ���ϸ�ȴ�
	���� �ؿ� �����ϴ� ������ �����ϸ�
	������ �Ʒ��� �б⿡ ������ ��ü�� �ȵȴ�

	�׸��� �Ʒ����� ����Ʈ ���� �ٽ� �ְų� �ٸ� ������ �����ϰ��� �Ѵٸ�
	�Լ��� ������ �ƴٰ� ������ ���� ���
*/

#include <iostream>

int Adder(int _num1 = 1, int _num2 = 2);

int main(void)
{

	std::cout << Adder() << std::endl;		// 3
	std::cout << Adder(3) << std::endl;		// 5
	std::cout << Adder(6, 8) << std::endl;	// 14

	return 0;
}

int Adder(int _num1, int _num2)
{

	return _num1 + _num2;
}