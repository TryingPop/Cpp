/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �̸����� 2
	����p 40 ~ 41

	�̸����� ��ݿ��� �Լ��� ����� ���Ǹ� �����ϴ� ����̴�
	�Լ��� ���𿡼� (��ȯ��) (�̸�����)::SimpleFunc(�Ű�����)�� �����ϸ� 
	������ ���� ���! �ݸ� ���� �κ��� �ּ�ģ �ڵ�ó�� �ٲ㵵 �ȴ�
*/

#include <iostream>

namespace BestComImpl 
{

	void SimpleFunc(void);
}

namespace ProgComImpl
{

	void SimpleFunc(void);
}

/*
// ������ ���� �߻�
void ProgComImpl::SimpleFunc(void);
*/

int main(void)
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void)
{

	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{

	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}


/*
namespace ProgComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}
*/