#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : usingDcl
	���ӽ����̽� ������ �Լ��� �����ϰ� ���
*/

namespace Hybrid {

	void HybFunc(void) {

		cout << "So simple function!" << endl;
		cout << "In namespace Hybrid" << endl;
	}
}

void HybFunc(void) {

	cout << "no namespace Hybrid" << endl;
}


int main()
{

	HybFunc();				// no namespace Hybrid ���
	using Hybrid::HybFunc;	// Hybrid namespace�� HybFunc�� HybFunc�� ȣ���ϱ� ���� ����
	HybFunc();				// In namespace Hybrid ���
	return 0;
}

