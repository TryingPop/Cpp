#include <string>

/*
��¥ : 2024. 3. 16
�̸� : �輺��
���� : 369����
	1���� ���ڸ� �ϳ��� ���
	���ڿ� 3, 6, 9�� ���� ������ ���
	3, 6, 9�� ������ŭ �ڼ��� ġ�� ����

	���� order�� �Ű������� �־��� ��,
	�ľ��� �ڼ��� Ƚ���� return�ϴ� solution �Լ� ����
*/

using namespace std;

int solution(int _order)
{

	int answer = 0;

	string strOrder = to_string(_order);
	for (const char c : strOrder)
	{

		if (c == '3' || c == '6' || c == '9') answer++;
	}

	return answer;
}