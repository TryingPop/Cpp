#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �̸�����
	�Լ��� �̸��� ���Ƽ� ����� ������ �ذ��ϱ� ���� ���� ����(?)
	::�� ���� ���ӽ����̽����� �Լ��� �о�´�
*/

namespace BestComImpl {

	void SimpleFunc(void) {

		cout << "BestComp�� ������ �Լ�" << endl;
	}
}

namespace ProgComImpl {

	void SimpleFunc(void) {

		cout << "ProgCom�� ������ �Լ�" << endl;
	}
}



int main()
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}