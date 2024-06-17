/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �̸����� ����� �Լ� ����� ���� ����
	���� p41 ~ 44

	������ �̸������� �ִ� �Լ��� ����ȣ���� �����ϴ�
	�׸��� �̸������� �ٸ� �̸����� �ȿ� ���Ե� �� �ִ�
	namespace ONE
	{

		namespace TWO { }
		namespace THREE { }
	}

	���� ��� ���� ONE::TWO::... �������� ������ �����ϴ�

	std::cout, std::cin, std::endl�
	std �̸������� ����� �͵��̴�
	�̸��浹�� �������� C++ ǥ�ؿ��� �����ϴ� �پ��� ��ҵ���
	�̸����� std�ȿ� ����Ǿ� �ִ�
*/

#include <iostream>

namespace BestComImpl
{

	void SimpleFunc(void);
}

namespace BestComImpl
{

	void PrettyFunc(void);
}

namespace ProgComImpl 
{

	void SimpleFunc(void);
}

int main(void)
{

	BestComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void)
{

	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc();				// ���� �̸�����
	ProgComImpl::SimpleFunc();	// �ٸ� �̸�����
}

void BestComImpl::PrettyFunc(void)
{

	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{

	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}