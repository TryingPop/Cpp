#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �̸�����
	�̸����� �Լ��� ���� �����ϰ� ���Ŀ� �����ϴ� ���
*/

namespace BestComImpl {

	void SimpleFunc(void);
}

namespace ProgComImpl {

	void SimpleFunc(void);
}

int main()
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void) {

	cout << "BestCom�� ������ �Լ�" << endl;
}

void ProgComImpl::SimpleFunc(void) {

	cout << "ProgCom�� ������ �Լ�" << endl;
}