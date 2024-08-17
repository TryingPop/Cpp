/*
��¥ : 2024. 8. 17
�̸� : �輺��
���� : �̷� Ż��
	1 x 1 ũ���� ĭ��� �̷���� 
	���簢�� ���� ������ �̷ο��� Ż���Ϸ��� �Ѵ�

	�� ĭ�� ��� �Ǵ� ������ �����Ǿ� ������,
	������ �� ĭ�� ������ �� ����
	��η� �� ĭ���θ� �̵��� �� �ִ�

	��ε� �� �� ĭ���� �̷θ� ���������� ���� �ִµ�,
	�� ���� ������ ��ܼ��� �� �� �ִ�
	���� ���� ��ε� �� �� ĭ�� �ִ�
	����, ��� �������� ���� ������ �ִ� ĭ���� �̵��Ͽ�
	������ ��� �� �̷θ� ���������� ���� �ִ� ĭ���� �̵��ϸ� �ȴ�

	�̶� ���� ������ ����� �ʾҴ��� �ⱸ�� �ִ� ĭ�� ������ �� �ִ�
	�̷ο��� �� ĭ�� �̵��ϴµ� 1�ʰ� �ɸ��ٰ� �� ��,
	�ִ��� ������ �̷θ� ���������µ� �ɸ��� �ð��� ���Ϸ� �Ѵ�

	�̷θ� ��Ÿ�� ���ڿ� �迭 maps�� �Ű������� �־��� ��
	�̷θ� Ż���ϴµ� �ʿ��� �ּ� �ð��� return �ϴ� solution �Լ��� ����
	���� Ż���� �� ���ٸ� -1�� return

	maps�� ���̴� 5 �̻� 100 ������ �ڿ���

	maps[i]�� ���̴� 5 �̻� 100 ������ �ڿ���

	maps[i]�� ���� 5���� ���ڵ�� �̷���� �ִ�
	S : ��������, E : �ⱸ, L : ����, O : ���, X : ��

	���������� �ⱸ, ������ �׻� �ٸ� ���� �����ϸ� 1������ �����Ѵ�

	�ⱸ�� ������ ������� �ʾƵ� ������ �� ������,
	��� ��� �ⱸ, ����, ���� ������ ������ ������ �� �ִ�

	parameter
	{ "SOOOL",
	  "XXXXO",
	  "OOOOO",
	  "OXXXX",
	  "OOOOE" }


	return
	16


	sol
	�̷ΰ� ������ ���� �ִ�
		S	O	O	O	L
		X	X	X	X	O
		O	O	O	O	O
		O	X	X	X	X
		O	O	O	O	E

	�̵� ĭ���� ������ ���� ǥ���ϸ�
		0	1	2	3	4
		X	X	X	X	5
	   10	9	8	7	6
	   11	X	X	X	X
	   12  13  14  15  16

	������ �̵��ϸ� 4���� ������ ����
	���������� �����ϴ� ����� �ȴ�
*/

#include <string>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

struct Pos
{

	/*
	
	BFS Ž���� �� ��ǥ
	*/
	int r;			// �� = y
	int c;			// �� = x
	bool key;		// ���� ��� ����

public:
	Pos(bool _key, int _r, int _c)
		: key(_key), r(_r), c(_c) { }
};

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

	/*
	
	��ǥ�� ���� ������� Ȯ��
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(vector<string>& _maps)
{

	/*
	
	BFS
	*/
	int row = _maps.size();
	int col = _maps[0].size();

	// ���� ��� ����, ���� y, ���� x�� �����ϴµ� �ּ� ���� ��´�
	vector<vector<vector<int>>> move(2, vector<vector<int>>(row, vector<int>(col, -1)));

	queue<Pos> q;
	pii e;

	// ���������� �� ���� ã��
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_maps[r][c] == 'S')
			{

				q.push(Pos(false, r, c));
				move[0][r][c] = 0;
			}
			else if (_maps[r][c] == 'E') e = mp(r, c);
		}
	}

	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	while (q.size())
	{

		Pos node = q.front();
		q.pop();

		int cur = move[node.key][node.r][node.c];

		for (int i = 0; i < 4; i++)
		{

			int nextR = node.r + dirR[i];
			int nextC = node.c + dirC[i];

			if (ChkInvalidPos(nextR, nextC, row, col)
				|| _maps[nextR][nextC] == 'X') continue;

			// ���� ������ Ȯ��
			bool key = node.key || _maps[nextR][nextC] == 'L';

			// �̹� �湮?
			if (move[key][nextR][nextC] != -1) continue;

			// �湮 �������Ƿ� �ش� ��ҷ� �̵� ����
			move[key][nextR][nextC] = cur + 1;
			q.push(Pos(key, nextR, nextC));
		}
	}

	return move[1][e.first][e.second];
}

int solution(vector<string> _maps)
{

	/*
	
	BFS ����
	*/
	int answer = BFS(_maps);
	return answer;
}