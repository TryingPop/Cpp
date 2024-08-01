/*
��¥ : 2024. 8. 1
�̸� : �輺��
���� : �� ť �� ���� �����
	���̰� ���� �� ���� ť�� �־�����
	�ϳ��� ť�� ��� ���Ҹ� �����ϰ�,
	����(pop)�� ���Ҹ� �ٸ� ť�� ����ִ�(insert) �۾��� ����
	�� ť�� ���� ���� ������ ������� �Ѵ�

	�̶� �ʿ��� �۾��� �ּ� Ƚ���� ã������ �Ѵ�
	1���� pop�� 1���� insert�� ���ļ� �۾��� 1ȸ ������ ������ �����Ѵ�

	ť�� �迭�� ǥ���ϸ�,
	�迭 ���ʿ� �������� ���� ������� �������� �ǹ��Ѵ�

	���̰� ���� �� ���� ť�� ��Ÿ���� ���� �迭
	queue1, queue2�� �Ű������� �־��� ��,
	�� ť�� ���� ���� ���� ����� ���� �ʿ��� �۾��� �ּ�Ƚ����
	return �ϴ� solution �Լ��� ����
	���� ���� ���� �� ���ٸ� -1�� ���

	queue1, queue2�� ���̴� 30�� ������ �ڿ���
	queue1, queue2 ������ ũ��� 10�� ������ �ڿ���


	parameter
	{ 3, 2, 7, 2 }, { 4, 6, 5, 1 }


	return
	2


	sol
	{ 2, 7, 2, 4 }, { 6, 5, 1, 3 }���� ����� �ȴ�
*/

#include <vector>

#define ll long long

using namespace std;

inline ll GetSum(vector<int>& _arr)
{

	/*
	
	�迭�� ���� ã���ش�
	*/
	ll ret = 0LL;
	for (int num : _arr)
	{

		ret += num;
	}

	return ret;
}

inline int GetRet(int _l, int _r, int _size)
{

	/*
	
	l, r�� �������� 
	ť���� �ּ� �� �� �������ϴ��� ã���ش�
	*/
	if (_r < _size - 1) return _r - _l + 1 + _size;
	else return _r - _size + 1 + _l;
}

int solution(vector<int> _queue1, vector<int> _queue2)
{

	/*
	
	�� ������
	*/

	// ť �̾���̱�
	_queue1.insert(_queue1.end(), _queue2.begin(), _queue2.end());

	// ���ο� �̸�
	vector<int>& link = _queue1;

	ll find = GetSum(link);

	// Ȧ���� ���� �������
	if (find % 2) return -1;

	// �� ������
	find /= 2;			// ã�� ��

	int l = 0;			// ����
	int r = 0;			// ������
	int answer = -1;	// �ּ� ����Ƚ��
	ll cur = link[0];	// ���� ������
	int size = _queue2.size();
	
	while (l < link.size() && r < link.size())
	{

		// ���� ���
		if (cur == find)
		{

			// ����Ƚ�� �ּ� �� ���� �Ǻ�
			int cnt = GetRet(l, r, size);
			if (answer == -1 || cnt < answer) answer = cnt;
		}

		// ���� ���� ����
		if (cur < find) cur += link[++r];
		else cur -= link[l++];
	}

	return answer;
}