/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �̸������� ��Ī ����
	���� p47 ~ 49

	�Ʒ� ������ ���� ������ AAA::BBB::CCC�� ���ο� ��Ī ABC�� �ο��ؼ�
	���� �ҷ����� �� �� �ִ�
*/

#include <iostream>

using namespace std;

namespace AAA
{

	namespace BBB
	{

		namespace CCC
		{

			int num1;
			int num2;
		}
	}
}

int main(void)
{

	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;
	cout << ABC::num1 << endl;			// 20
	cout << ABC::num2 << endl;			// 30

	return 0;
}