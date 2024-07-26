/*
��¥ : 2024. 7. 26
�̸� : �輺��
���� : 2�� ���Ϸ� �ٸ� ��Ʈ
	���� ���� x�� ���� �Լ� F(x)�� ������ ���� �����Ѵ�
	x���� ũ�� x�� ��Ʈ�� 1 ~ 2�� �ٸ� ���� �߿� ���� ���� ��

	�������� ��� �迭 numbers�� �Ű������� �־��� ��,
	numbers�� ��� ���鿡 ���Ͽ� �� �� F�� ���� �迭�� ���ʴ�� ���
	return �ϴ� solution �Լ� ����

	numbers�� ���̴� 10�� ������ �ڿ����̰�,
	numbers�� ��� ���Ҵ� 10^15���� ���� ���̾ƴ� �����̴�

	parameter
	{ 2, 7 }


	return
	{ 3, 11 }


	sol
	2�� 0000'0010�̴�
	2���� 3�� 2���� ū �� �߿� ���� ���� ���̸�
	0000'0011�̹Ƿ�
	2�� ��Ʈ�� 1�� �ٸ���

	7�� 0000'0111�̴�
	7�� ��Ʈ�� 1�� �ٸ� �� �� 7���� ũ�鼭 ���� ������
	0000'1111, 15�̴�
	7�� ��Ʈ�� 2�� �ٸ����� 
	0000'1011, 11�̴�
*/

#include <vector>

#define ll long long

using namespace std;

inline ll F(ll _num)
{

	/*
	
	�� �������� 0�� ã�� 1�� �ٲ۴�
	�׷��� x���� ū ���� ����ȴ�

	�ٲ� 0�� �������� �����ʿ� 1�� �����ϸ�
	�ٲ� 0�� ���� ����� 1�� 0���� �ٲ۰� ���� ���� ���� �ȴ�
	*/
	int b = -1;

	// 2^50 > 10^15
	for (int i = 0; i <= 50; i++)
	{

		if (_num & (1LL << i)) b = i;
		else 
		{

			_num |= 1LL << i;
			if (b != -1) _num ^= 1LL << b;

			return _num;
		}
	}

	return -1;
}

vector<ll> solution(vector<ll> _numbers)
{

	vector<ll> answer;
	answer.reserve(_numbers.size());

	for (const ll num : _numbers)
	{

		ll ret = F(num);
		answer.push_back(ret);
	}

	return answer;
}