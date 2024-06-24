/*
��¥ : 2024. 6. 24
�̸� : �輺��
���� : �� ����
	�� ���ڿ� �������� ���� ���� k��,
	��Ȯ�� ���� ũ�⸦ ���� �迭 tangerine
	�� �Ű������� �־��� ��,

	k���� �� �� ũ�Ⱑ ���� �ٸ� ������ ���� 
	�ּڰ��� return �ϴ� solution �Լ��� ����

	tangerine�� ���Ҵ� 1000�� ������ �ڿ����̰�,
	k <= tangerine�� �����̰�, tangerine�� ���̴� 10�� �����̴�

	parameter
	6, { 1, 3, 2, 5, 4, 5, 2, 3 }


	return
	3


	solve
	1, 4�� 1���� �ְ�
	2, 3, 5�� ���� ���� 2���� �ִ�
	�ٸ� ũ��� ����

	2, 4, 5�� ��� ������ 6�����ǰ�
	���� �ٸ� ũ�� ������ 3���� �ּҰ� �ȴ�
	�׷��� 3�� ��ȯ
*/

#include <vector>
#include <algorithm>

using namespace std;

void CompactVec(vector<int>& _vec)
{

	sort(_vec.begin(), _vec.end());

	int val = 0;
	int before = 0;

	for (int i = 0; i < _vec.size(); i++)
	{

		if (before != _vec[i])
		{

			before = _vec[i];
			val++;
		}

		_vec[i] = val;
	}
}

void CountVec(const vector<int>& _vec, vector<int>& _ret)
{

	for (const int num : _vec)
	{

		_ret[num]++;
	}
}

int GetRet(vector<int>& _cnt, int _k) 
{

	// Greedy
	int ret = 0;
	sort(_cnt.begin(), _cnt.end(), greater<int>());
	for (const int num : _cnt)
	{

		_k -= num;
		ret++;
		if (_k <= 0) break;
	}

	return ret;
}

int solution(int _k, vector<int> _tangerine)
{

	int answer = 0;

	CompactVec(_tangerine);

	vector<int> cnt(_tangerine.back() + 1, 0);
	CountVec(_tangerine, cnt);

	answer = GetRet(cnt, _k);

	return answer;
}