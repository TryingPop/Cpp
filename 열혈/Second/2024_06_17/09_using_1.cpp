/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : using�� �̿��� �̸������� ���
	���� p44 ~ 45
	
	using Ű���带 �̿��ϸ��̸����� �ȿ� ����� �Լ��� 
	�������� ���� �׳�ȣ���� �� �ִ�

	�Ʒ� ������ ����, HybFunc�� �̸��ﰣ Hybrid���� ã����� ������ �����̴�
	���⼭ HybFunc�� ������ �� ���� �ְ� �Լ��� �� �� �ִ�
	���������� ����Ǿ����Ƿ� ����� ������ ����� ������ ȿ���� �Ϥ��� �ȴ�

	���α׷� ��ü ������ ȿ���� ��ġ�� �Ϸ���
	���������� ���������� �Լ� �ۿ� ������ �ؾ� �Ѵ�
*/

#include <iostream>

namespace Hybrid
{

	void HybFunc(void)
	{

		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid" << std::endl;
	}
}

int main(void)
{

	using Hybrid::HybFunc;
	HybFunc();
	return 0;
}