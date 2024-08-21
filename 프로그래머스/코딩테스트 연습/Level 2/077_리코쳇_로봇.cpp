/*
��¥ : 2024. 8. 21
�̸� : �輺��
���� : ������ �κ�
	������ �κ��̶�� ��������� �ִ�

	�� ��������� ���ڸ�� ������ ������ ���� �����̴� ��������,
	���� ��ġ���� ��ǥ ��ġ���� �ּ� �� ������ ������ �� �ִ��� ���ϴ� �����̴�

	�� ���ӿ��� ���� �������� ��, ��, ��, �� 4 ���� ��
	�ϳ��� �����ؼ� ������ ���� ��ֹ��̳� �� ���� �ε��� ������
	�̲����� �̵��ϴ� ���� �� ���� �̵����� ģ��

	�������� ���¸� ��Ÿ���� ���ڿ� �迭 board�� �־����� ��,
	���� ��ǥ ��ġ�� �����ϴµ� �ּ� �� �� �̵��ؾ� �ϴ���
	return �ϴ� solution �Լ��� ����

	���� ��ǥ ��ġ�� ������ �� ���ٸ� -1�� return

	board�� ���� 100 ���� 3 �̻��� �ڿ���
	board�� ���� ���̴� 100 ���� 3 �̻��� �ڿ���
	board�� ������ ���̴� ��� �����ϴ�

	board�� ���ҿ��� "."�� �̵� ������ �� ������,
	"D"���̵��� �� ���� ��ֹ���,
	"R"�� ���� ��ġ��,
	"G"�� ��ǥ ��ġ�� ��Ÿ����

	"R", "G"�� �� ������ �����Ѵ�

	parameter
	{ 

		"...D..R", 
		".D.G...", 
		"....D.D", 
		"D....D.", 
		"..D...." 
	}


	return
	7


	sol
	�Ʒ�, ����, �Ʒ�, ����,
	��, ������, �� ������ �̵��ϸ�

	��ǥ������ �����ϰ� �̰� �ּ��̴�
*/

#include <string>
#include <vector>
#include <queue>
#include <utility>

#define pii pair<int, int>
#define mp make_pair

#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

	/*
	
	��ȿ �������� Ȯ��
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(vector<string>& _board)
{

	/*
	
	BFS ���ð� BFS ����
	*/

	// ����
	int row = _board.size();
	int col = _board[0].size();
	int big = Max(row, col);

	vector<vector<int>> move(row, vector<int>(col, -1));

	pii s, e;
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_board[r][c] == 'R') s = mp(r, c);
			else if (_board[r][c] == 'G') e = mp(r, c);
		}
	}

	// BFS
	move[s.first][s.second] = 0;
	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };
	queue<pii> q;

	q.push(s);

	while (q.size())
	{

		pii node = q.front();
		q.pop();

		int cur = move[node.first][node.second];

		for (int dir = 0; dir < 4; dir++)
		{

			int nextR = node.first;
			int nextC = node.second;

			// �̲������� ����
			for (int i = 0; i <= big; i++)
			{

				int chkR = nextR + dirR[dir];
				int chkC = nextC + dirC[dir];

				// �浹 �� �����
				if (ChkInvalidPos(chkR, chkC, row, col)
					|| _board[chkR][chkC] == 'D') break;

				nextR += dirR[dir];
				nextC += dirC[dir];
			}

			// �̹� �湮������ Ž�� X
			if (move[nextR][nextC] != -1) continue;
			move[nextR][nextC] = cur + 1;
			q.push(mp(nextR, nextC));
		}
	}

	return move[e.first][e.second];
}

int solution(vector<string> _board)
{

	int answer = BFS(_board);
	return answer;
}