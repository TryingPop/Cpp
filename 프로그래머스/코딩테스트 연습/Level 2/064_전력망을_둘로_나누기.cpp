/*
��¥ : 2024. 8. 8
�̸� : �輺��
���� : ���¸��� �ѷ� ������
	n���� ����ž�� ������ ���� �ϳ��� Ʈ�� ���·� ����
	�� ������ �� �ϳ��� ��� ������ ���¸� ��Ʈ��ũ�� 2���� ����
	�� ���¸��� ���ԵǴ� ����ž�� ������ �ִ��� ����ϰ� ���߰��� �Ѵ�

	����ž�� ���� n, �׸��� ���� ���� wires�� �Ű������� �־��� ��,
	������ �� �ϳ��� ��� ����ž ������ ������ ����ϵ���
	�� ���¸����� �������� ��,
	�� ���¸��� ������ �ִ� ����ž ������ ���̸� 
	return �ϴ� solution �Լ� ����

	n�� 2�̻� 100������ �ڿ���
	wires�� ���̰� n - 1�� 2���� �迭
	wires�� �� ���Ҵ� 2���� �̷���� { v1, v2 } �̸� v1, v2�� �ڿ����̰�
	v1�� v2�� �������� ����Ǿ� ������ �ǹ��Ѵ�
	v1, v2�� n������ �ڿ����̴�
	wires�� Ʈ���� �ƴ� ���� �־����� �ʴ´�


	parameter
	9, { { 1, 3 },{ 2, 3 },{ 3, 4 },{ 4, 5 },{ 4, 6 },{ 4, 7 },{ 7, 8 },{ 7, 9 } }


	return
	3


	sol
	�׷����� ������ ���� �����ε�	
		1	5	8
		|	|	|
		3 - 4 - 7
		|	|	|
		2	6	9
	
	3���� 4�� ���� ������ ���� ���
	1, 2, 3 �׷�1��, 
	4, 5, 6, 7, 8, 9 �׷� 2�� ������

	�� �� �� �׷��� ���� �ּ� �� �ϳ��̴�
*/

#include <algorithm>
#include <vector>

#define ABS(X)	((X < 0) ? -(X) : (X));
using namespace std;

inline void SetLine(const vector<vector<int>>& _wires, vector<vector<int>>& _ret) 
{

	for (const vector<int>& cur : _wires)
	{

		_ret[cur[0]].push_back(cur[1]);
		_ret[cur[1]].push_back(cur[0]);
	}
}

#if first
inline bool ChkDisConn(const int _n1, const int _n2, const int _not1, const int _not2)
{

	/*
	
	������ �������� Ȯ��
	*/
	if ((_n1 == _not1 && _n2 == _not2)
		|| (_n1 == _not2 && _n2 == _not1)) return true;

	return false;
}

inline int DFS(int _f, vector<bool>& _visit, const vector<vector<int>>& _line, const int _not1, const int _not2)
{

	/*
	
	����� ���� ���� Ȯ��
	*/
	int ret = 1;

	for (int t : _line[_f])
	{

		if (_visit[t] || ChkDisConn(_f, t, _not1, _not2)) continue;
		_visit[t] = true;

		ret += DFS(t, _visit, _line, _not1, _not2);
	}

	return ret;
}

#else

inline void DFS(int _f, int _parent, vector<int>& _size, const vector<vector<int>>& _line)
{

	if (_size[_f]) return;
	_size[_f] = 1;

	for (int t : _line[_f])
	{

		if (t == _parent) continue;
		DFS(t, _f, _size, _line);
		
		_size[_f] += _size[t];
	}
}


#endif

int solution(int _n, vector<vector<int>> _wires)
{

	int answer = _n;

	vector<vector<int>> line(_n + 1, vector<int>());
	SetLine(_wires, line);

#if first

	vector<bool> visit(_n + 1);

	// �� ���� �����鼭 �ּ� ����� ���� ã�´�
	for (const vector<int>& dis : _wires)
	{

		fill(visit.begin(), visit.end(), false);
		visit[1] = true;

		int group1 = DFS(1, visit, line, dis[0], dis[1]);
		int group2 = _n - group1;

		int chk = ABS(group1 - group2);

		if (chk < answer) answer = chk;
	}
#else

	vector<int> size(_n + 1, 0);

	DFS(1, 0, size, line);

	for (int i = 2; i <= _n; i++)
	{

		int group1 = size[i];
		int group2 = _n - size[i];

		int chk = ABS(group1 - group2);
		if (chk < answer) answer = chk;
	}

#endif
	return answer;
}