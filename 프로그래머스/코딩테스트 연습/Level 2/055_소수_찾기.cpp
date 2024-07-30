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

inline bool IsPrime(int _num)
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

inline void DFS(int _depth, vector<int>& _cnt, set<int>& _ret, set<int>& _visit, int _num)
{

	/*
	
	������� �Ҽ��� use�� ����
	*/

	if (_visit.count(_num)) return;
	_visit.insert(_num);

	if (IsPrime(_num)) _ret.insert(_num);
	if (!_depth) return;

	for (int i = 9; i >= 0; i--)
	{

		if (!_cnt[i]) continue;
		_cnt[i]--;

		DFS(_depth - 1, _cnt, _ret, _visit, _num * 10 + i);
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
	set<int> ret;					// ���� �� �ִ� �Ҽ� ����
	set<int> visit;					// ��湮 ����
	int dep = _numbers.length();

	for (const char c : _numbers)
	{

		cnt[c - '0']++;
	}

	DFS(dep, cnt, ret, visit, 0);
	answer = ret.size();
	return answer;
}