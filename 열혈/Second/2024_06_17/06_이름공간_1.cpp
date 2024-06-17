/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �̸�����
	���� p36 ~ 39

	�̸������� �̸��� �ٿ����� ������ �ǹ��Ѵ�
	Ư�� ������ �̸��� �ٿ��ֱ� ���� ������ ����̴�

	���α׷��� ����ȭ���Ǿ� ���鼭 �̸��� �浹������ �����ߴ�
	������Ʈ�� �Ը� ū ��� ���� �����Ͽ� �����Ͽ� �������� ��,
	������ �� �̸��浹�� �� �� �ִ�

	�Լ� �� ������ �̸��� ��� ���� ���� �ذ��� �� �ִ�
	������ �̴� �Ѱ谡 �ִ�

	�̸�����(namespace)�̶�� ������ �����ؼ� 
	�̷��� ������ ���� �ٺ����� �ذ�å�� ������ �ִ�

	������ ::�� ������ �������� ������(scope resolution operator)�� �Ѵ�
	�̸������� ������ �� ����ϴ� �������̴�
*/

#include <iostream>

namespace BestComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

int main(void)
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}