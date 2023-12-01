#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �̸�����
	������ �̸� ���������� �̸����� ��ð� �ʿ����
	�׸��� �̸� ���� �ȿ� �̸� ������ ������ �� �ִ�
*/

namespace BestComImpl {

	void SimpleFunc(void);
	void PrettyFunc(void);
}

namespace ProgComImpl {

	void SimpleFunc(void);
}

// �̸������ȿ� �̸������� ����
namespace Parent {

	int num = 0;

	namespace Child {

		int num = 1;
	}
}

int main()
{

	BestComImpl::SimpleFunc();
	cout << "Parent num : " << Parent::num << endl;
	cout << "Child num : " << Parent::Child::num << endl;

	return 0;
}


void BestComImpl::SimpleFunc(void) {

	cout << "BestCom�� ������ �Լ�" << endl;
	// BestComImpl::PrettyFunc()�� ����� �ʿ䰡 ����
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void) {

	cout << "So Pretty!!" << endl;
}

void ProgComImpl::SimpleFunc(void) {

	cout << "ProgCom�� ������ �Լ�" << endl;
}
