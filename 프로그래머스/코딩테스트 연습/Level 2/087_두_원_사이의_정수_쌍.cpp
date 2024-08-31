/*
��¥ : 2024. 8. 31
�̸� : �輺��
���� : �� �� ������ ���� ��
	x��� y������ �̷���� 2���� ���� ��ǥ�迡
	�߽��� ������ ���� �ٸ� ũ���� ���� �ΰ� �־�����
	�������� ��Ÿ���� �� ���� r1, r2�� �Ű������� �־��� ��,
	�� �� ������ ������ x��ǥ�� y��ǥ�� ��� ������ ���� ������
	return �ϴ� solution �Լ� ����

	�� �� ���� ���� �����Ͽ� ����

	r1, r2�� 100�� ������ �ڿ����̰�
	r1 < r2�̴�

	parameter
	2, 3


	return
	20


	sol
	y��� 1��и����� ������ ���� �ִ� ����
	(0, 1), (0, 2),
	(1, 2),
	(2, 1), (2, 2)
	�� �� 5���̴�

	�̸� 2��и�� x��,
	3��и�� y��, 4��и�� x���� ������
	�����ϹǷ� �� 20���̴�
*/

#include <cmath>

#define ll long long
#define E 1e-9

using namespace std;

inline ll MySqrt(ll _r, ll _i)
{

	/*
	
	E�� �ε��Ҽ��� ����
	*/
	if (_r <= _i) return 0;
	return sqrt((_r * _r) - (_i * _i)) + E
}

inline bool Add(ll _chk, ll _r, ll _i)
{

	/*
	
	�� ���� ��ġ���� Ȯ��
	*/
	return (_chk * _chk) == (_r * _r) - (_i * _i);
}

ll solution(int _r1, int _r2)
{

	/*
	
	����
	*/

	ll answer = 0;
	for (int i = 0; i < _r2; i++)
	{

		answer += MySqrt(_r2, i);
		ll chk = MySqrt(_r1, i);

		answer -= chk;
		if (Add(chk, _r1, i)) answer++;
	}

	answer--;
	answer *= 4;
	return answer;
}