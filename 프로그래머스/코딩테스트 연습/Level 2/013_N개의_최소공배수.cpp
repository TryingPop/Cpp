/*
��¥ : 2024. 6. 20
�̸� : �輺��
���� : N���� �ּҰ����
	�� ���� �ּҰ����(Least Common Multiple)�̶�
	�Էµ� �� ���� ��� �� ������ �Ǵ� ���� ���� ���ڸ� �ǹ��Ѵ�

	n���� ���� �ּ� ������� n���� ������ ��� �� ������ �Ǵ�
	���� ���� ���ڸ� �ǹ��Ѵ�

	n���� ���ڸ� ���� �迭 arr�� �ԷµǾ��� ��
	�� ������ �ּҰ������ ��ȯ�ϴ� �Լ� solution�� ����

	arr�� 1 �̻� 15������ �迭,
	arr�� ���Ҵ� 100 ������ �ڿ���

	parameter
	{ 2, 6, 8, 14 }


	return
	168
*/

#include <vector>

using namespace std;

int GetGCD(int _a, int _b)
{

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int solution(vector<int> _arr)
{

	int answer = 1;

	for (int num : _arr)
	{

		int gcd = GetGCD(answer, num);
		answer *= num / gcd;
	}

	return answer;
}