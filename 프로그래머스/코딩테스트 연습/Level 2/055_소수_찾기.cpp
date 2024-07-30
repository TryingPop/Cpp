/*
��¥ : 2024. 7. 30
�̸� : �輺��
���� : �Ҽ� ã��
	���ڸ� ���ڰ� ���� ���� ������ ������ִ�
	����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �Ѵ�

	�� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��,
	���� �������� ���� �� �ִ� ���� �ٸ� �Ҽ��� �� ������ 
	return �ϴ� solution �Լ� ����

	numbers�� ���� 1 �̻� 7 ������ ���ڿ�
	numbers�� 0 ~ 9 ���� ���ڸ����� �̷���� �ִ�
	013�� 0, 1, 3 ���ڰ� ���� ���� ������ ����� �ִٴ� �ǹ�

	parameter
	011


	return
	2


	sol
	11, 101 �� ���� �� �ִ�
*/

#include <string>
#include <vector>
#include <set>

#define ll long long

using namespace std;

bool IsPrime(int _num)
{

	/*
	
	�����佺 �׳׽� ü�� �Ҽ� ����
	*/
	if (_num < 2) return false;

	for (ll i = 2; i * i <= _num; i++)
	{

		if (_num % i) continue;

		return false;
	}

	return true;
}

void DFS(int _depth, vector<int>& _cnt, set<int>& _use, int _num)
{

	/*
	
	������� �Ҽ��� use�� ����
	*/
	if (!_use.count(_num) && IsPrime(_num)) _use.insert(_num);
	if (!_depth) return;

	for (int i = 0; i < 10; i++)
	{

		if (!_cnt[i]) continue;
		_cnt[i]--;

		DFS(_depth - 1, _cnt, _use, _num * 10 + i);
		_cnt[i]++;
	}
}

int solution(string _numbers)
{

	/*
	
	���Ʈ ����
	*/
	int answer = 0;
	vector<int> cnt(10, 0);			// ���� ���� Ȯ��
	set<int> use;					// ���� �� �ִ� �Ҽ� ����

	int dep = _numbers.length();

	for (const char c : _numbers)
	{

		cnt[c - '0']++;
	}

	DFS(dep, cnt, use, 0);
	answer = use.size();
	return answer;
}