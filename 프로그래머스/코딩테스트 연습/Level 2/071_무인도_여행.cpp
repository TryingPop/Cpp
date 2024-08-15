/*
��¥ : 2024. 8. 15
�̸� : �輺��
���� : ���ε� ����
	�������� �ٴٿ� 1x1 ũ���� �簢����� �̷���� 
	���簢�� ������ �����̸�,

	������ �� ĭ���� 'X' �Ǵ� 1���� 9 ������ �ڿ����� ���� �ִ�
	������ 'X'�� �ٴٸ� ��Ÿ����,

	���ڴ� ���ε��� ��Ÿ����
	�̶� ��, ��, ��, ��� ����Ǵ� ������ �ϳ��� ���ε��� �̷��

	������ �� ĭ�� ���� ���ڴ� �ķ��� ��Ÿ���µ�,
	��, ��, ��, ��� ����Ǵ� ĭ�� ���� ���ڸ� ��� ���� ����
	�ش� ���ε����� �ִ� ��ĥ���� �ӹ� �� �ִ����� ��Ÿ����

	� ������ � ���� �� ���� �޸��� �켱 �� ������
	�ִ� ��ĥ�� �ӹ� �� �ִ��� �˾ƺ� �� ��� ���� �����Ϸ� �Ѵ�

	������ ��Ÿ���� ���ڿ� �迭 maps�� �Ű������� �־��� ��,
	�� ������ �ִ� ��ĥ�� �ӹ��� �� �ִ��� �迭�� ������������ ���
	return �ϴ� solution �Լ� ����

	���� ���� �� �ִ� ���ε��� ���ٸ� -1�� return

	maps�� ���̴� 100 ���� 3�̻��� ����,
	maps[i]�� ���̵� 100���� 3�̻��� �����̰�
	maps[i]�� 'X' �Ǵ� 1�� 9 ������ �ڿ����� �̷���� ���ڿ��̴�
	������ ���簢�� ���´�


	parameter
	{ "X591X","X1X5X","X231X", "1XXX1" }


	return
	{ 1, 1, 27 }


	sol
	������ ���� ����ó�� ���ε� ������ ������
		X|	5	9	1  |X
		X|	1	X	5  |X
		X|	2	3	1  |X
		-----------------
		1|	X	X	X  |1

	�� ���ε����� ������ �� �ִ� ��¥�� ������ ���̹Ƿ�
	27, 1, 1 �� �ְ� �̸� �������� �����ϸ�
	1, 1, 27�̵ȴ�
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define mp make_pair
#define pii pair<int, int>

using namespace std;

inline bool ChkInvalidPos(const int _r, const int _c, const int _row, const int _col)
{

	/*
	
	��ȿ�� �ε������� �Ǻ�
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int GetDay(vector<string>& _maps, queue<pii>& _q)
{

	/*
	
	�ش� ���ε����� ������ �� �ִ� ��¥ ���
	*/
	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	int row = _maps.size();
	int col = _maps[0].size();

	int ret = 0;

	while (_q.size())
	{

		pii node = _q.front();
		_q.pop();

		for (int i = 0; i < 4; i++)
		{

			int nextR = node.first + dirR[i];
			int nextC = node.second + dirC[i];

			if (ChkInvalidPos(nextR, nextC, row, col)
				|| _maps[nextR][nextC] == 'X') continue;

			ret += _maps[nextR][nextC] - '0';
			_maps[nextR][nextC] = 'X';

			_q.push(mp(nextR, nextC));
		}
	}

	return ret;
}

vector<int> solution(vector<string> _maps)
{

	/*
	
	BFS
	*/
	vector<int> answer;
	
	int row = _maps.size();
	int col = _maps[0].size();

	queue<pii> q;

	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_maps[r][c] == 'X') continue;

			int day = _maps[r][c] - '0';
			_maps[r][c] = 'X';

			q.push(mp(r, c));
			day += GetDay(_maps, q);
			answer.push_back(day);
		}
	}

	if (answer.empty()) answer.push_back(-1);
	else sort(answer.begin(), answer.end());

	return answer;
}