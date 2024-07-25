/*
��¥ : 2024. 7. 25
�̸� : �輺��
���� : ������4���
	���� ����� ����� 2 x 2 ���·� 4���� �پ����� ��� ������鼭
	������ ��� �����̴�

	2 x 2�� ��ġ�� ����� ���� ���� ������,
	�Ѳ����� ��������

	����� ������ �Ŀ� ���� �ִ� ����� �Ʒ��� ������
	�� ������ ä��� �ȴ�

	���� �� ������ ä�� �Ŀ� �ٽ� 2x2���·�
	���� ����� ����� ���̸� �ٽ� ��������
	�������� �ݺ��ϰ� �ȴ�

	�Է����� ����� ù ��ġ�� �־����� ��,
	�������� ����� ��� �� ������ �Ǵ��ϴ� ���α׷��� �����ض�

	�Է����� ���� ���� m, �� n�� ���� ��ġ ���� board�� ���´�
	n, m �� 2�̻� 30������ ����

	board�� ���� n�� ���ڿ� m���� �迭�� �־�����
	����� ��Ÿ���� ���ڴ� A���� Z�� ���ȴ�

	�Է����� �־��� ���� ������ ������ 
	�� ���� ����� �������� ���

	parameter
	4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }


	return
	14


	sol
	CCBDE
	AAADE
	AAABF
	CCBBF

	����ε�
	A 2 x 2 ����� 2�� �ִ�
	�̸� �����ϸ�

	CCBDE
	   DE
	   BF
	CCBBF

	���ǰ�
	���⼭ CCB ����� �����´�

	   DE
	   DE
	CCBBF
	CCBBF
	�׸��� �ٽ� 2 x 2 ����� �����ϸ�
	C, B�� �ִ�

	�̵��� �����ϸ�

	   DE
	   DE
	    F
		F

	���ǰ�
	�ٽ� ����� ������

	    E
		E
	   DF
	   DF
	���ȴ�

	�� �̻� 2 x 2 ����� ����
	���ŵ� ����� 14���̴�
*/

#include <string>
#include <vector>
#include <queue>

#define mp make_pair
#define pi pair<int, int>
#define EMPTY '_'

using namespace std;

queue<pi> q;
vector<int> dirR = { 1, 0, 1 };
vector<int> dirC = { 0, 1, 1 };

inline int BreakBlock(vector<string>& _board)
{

	/*
	
	��� �μ��� �� �μ� ��� ���� ��ȯ�ϴ� �Լ�
	*/

	int ret = 0;

	while (q.size())
	{

		pi node = q.front();
		q.pop();

		if (_board[node.first][node.second] != EMPTY)
		{

			_board[node.first][node.second] = EMPTY;
			ret++;
		}

		for (int i = 0; i < 3; i++)
		{

			int nextR = node.first + dirR[i];
			int nextC = node.second + dirC[i];

			if (_board[nextR][nextC] == EMPTY) continue;
			_board[nextR][nextC] = EMPTY;
			ret++;
		}
	}

	return ret;
}

inline void MoveDown(vector<string>& _board) 
{

	/*
	
	��� �Ʒ��� ������
	*/

	int row = _board.size();
	int col = _board[0].size();

	for (int c = 0; c < col; c++)
	{

		int bot = row - 1;
		for (int r = row - 1; r >= 0; r--)
		{

			if (_board[r][c] == EMPTY) continue;

			_board[bot][c] = _board[r][c];
			if (bot != r) _board[r][c] = EMPTY;
			bot--;
		}
	}
}

inline bool FindSquare(const vector<string>& _board)
{

	/*
	
	2 x 2 ��� ã��
	����� ������ �����ϰ� ��� 1�� ���� true
	������ false
	*/

	int row = _board.size();
	int col = _board[0].size();

	for (int r = 0; r < row - 1; r++)
	{

		for (int c = 0; c < col - 1; c++)
		{

			int cur = _board[r][c];
			if (cur == EMPTY
				|| cur != _board[r][c + 1]
				|| cur != _board[r + 1][c]
				|| cur != _board[r + 1][c + 1]) continue;

			q.push(mp(r, c));
		}
	}

	return q.size();
}

int solution(int _m, int _n, vector<string> _board)
{

	int answer = 0;

	while (FindSquare(_board))
	{

		answer += BreakBlock(_board);
		MoveDown(_board);
	}

	return answer;
}