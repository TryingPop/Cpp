/*
��¥ : 2024. 9. 8
�̸� : �輺��
���� : ���� ����
	���� ���̰� n, ���� ���̰� m�� ���� ����� �� �ӿ��� ������ �߰ߵǾ���
	������ ���� ����� ������ �����ִ�

	����� ���߰��� �������� �� �ϳ��� ���� �� ���� ��,
	���� ���� ������ ���� �� �ִ� ���߰��� ��ġ�� ã������ �Ѵ�
	���߰��� �� �ϳ��� �����ϴ� ���¿��� �ϸ�,
	���� �� ���̿� ���߰��� ���� �� ����

	���߰��� ��ġ�� ��ġ �Ʒ��� ������ �����
	���� ���߰��� ���� ����� �Ϻθ� ������ �ش� �����
	���� ��� ������ ��� ���� �� �ִ�

	���ʰ��� ���� �� �ִ� �������� ���߰��� ������ 
	���� ������� ũ�⸦ ��� ���� ���̴�

	������ ���� ���� ���� ����� ��Ÿ���� 
	2���� ���� �迭 land�� �Ű������� �־��� ��,
	���߰� �ϳ��� ��ġ�� ���� �� �ִ� ���� ���� ��������
	return �ϴ� solution �Լ� ����

	���� ���� ���� = land�� ���̴� 500������ �ڿ����̰�
	���� ���� ���� land[i]�� ���̵� 500������ �ڿ����̴�

	land[i][j]�� 0�̸� �� ����, 1�̸� ������ �ִ� ���� �ǹ��Ѵ�


	parameter
	{ { 0, 0, 0, 1, 1, 1, 0, 0 }, 
	  { 0, 0, 0, 0, 1, 1, 0, 0 }, 
	  { 1, 1, 0, 0, 0, 1, 1, 0 }, 
	  { 1, 1, 1, 0, 0, 0, 0, 0 }, 
	  { 1, 1, 1, 0, 0, 0, 1, 1 } }


	return
	9


	sol
	���� ���� ������ ����
		0	0	0	1	1	1	0	0
		0	0	0	0	1	1	0	0
		1	1	0	0	0	1	1	0
		1	1	1	0	0	0	0	0
		1	1	1	0	0	0	1	1

	���� ����� ���Է� ����� ǥ���ϸ� 
	���� ������ ����
		0	0	0	7	7	7	0	0
		0	0	0	0	7	7	0	0
		8	8	0	0	0	7	7	0
		8	8	8	0	0	0	0	0
		8	8	8	0	0	0	2	2

	���� ���߰��� ���� ��ġ�� ������ 
	7 + 2 = 9�� �ִ밡�ȴ�
								|
		0	0	0	7	7	7	0	0
		0	0	0	0	7	7	0	0
		8	8	0	0	0	7	7	0
		8	8	8	0	0	0	0	0
		8	8	8	0	0	0	2	2
*/

#include <vector>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

	/*
	
	��ȿ ��ǥ Ȯ��
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(queue<pii>& _q, vector<vector<int>>& _land, int _g)
{

	/*
	
	������ ���� ���� ����
	*/

	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	int row = _land.size();
	int col = _land[0].size();

	int oil = 1;

	while (_q.size() > 0)
	{

		pii node = _q.front();
		_q.pop();

		for (int i = 0; i < 4; i++)
		{

			int nR = node.first + dirR[i];
			int nC = node.second + dirC[i];

			if (ChkInvalidPos(nR, nC, row, col) || _land[nR][nC] != 1) continue;
			_land[nR][nC] = _g;
			oil++;

			_q.push(mp(nR, nC));
		}
	}

	return oil;
}

inline int GetRet(vector<vector<int>>& _land)
{

	/*
	
	���� ���� ����, ���߰� �ձ�
	*/

	// ���� ���� ����
	queue<pii> q;
	vector<int> oils(2, 0);

	int row = _land.size();
	int col = _land[0].size();

	int g = 1;
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_land[r][c] != 1) continue;
			_land[r][c] = ++g;
			q.push(mp(r, c));
			int oil = BFS(q, _land, g);
			oils.push_back(oil);
		}
	}

	// ���߰� �ձ�
	int ret = 0;
	vector<bool> use(oils.size(), false);

	for (int c = 0; c < col; c++)
	{

		for (int r = 0; r < row; r++)
		{

			if (_land[r][c] == 0) continue;
			use[_land[r][c]] = true;
		}

		int chk = 0;
		for (int i = 2; i < use.size(); i++)
		{

			if (!use[i]) continue;
			use[i] = false;
			chk += oils[i];
		}

		ret = Max(chk, ret);
	}

	return ret;
}

int solution(vector<vector<int>> _land)
{

	/*
	
	BFS
	�ð� ���⵵ O(NM)
	N, M : land �� ��� ���� ũ��
	*/
	int answer = GetRet(_land);
	return answer;
}