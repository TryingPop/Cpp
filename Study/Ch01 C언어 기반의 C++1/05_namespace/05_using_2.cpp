#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : usingDcl
	���ӽ����̽����� ��� �Լ��� ������ �����ϰ� ���
*/

namespace Hybrid {

	void HybFunc(void) {

		cout << "So simple function!" << endl;
		cout << "In namespace Hybrid" << endl;
	}
}
/*
void HybFunc(void) {

	cout << "no namespace Hybrid" << endl;
}
*/

int main()
{

	using namespace Hybrid;	// Hybrid namespace�� �Լ����� Hybrid::�Լ���(������) �� �ƴ� �Լ���(������)���� �Լ�ȣ�� �����ϰ� ���ش� 
							// no namespace Hybrid �ּ��� ���� ��� ��ȣ�ϴٴ� ������ ���

	HybFunc();				// In namespace Hybrid ���
	return 0;
}
