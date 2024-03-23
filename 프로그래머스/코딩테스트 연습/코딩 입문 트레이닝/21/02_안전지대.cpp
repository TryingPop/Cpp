#include <vector>

/*
��¥ : 2024. 3. 23
�̸� : �輺��
���� : ��������
	���ڰ� �ִ� ������ ���ڿ� ������ ��, �Ʒ�, 
	��, ��,	�밢�� ĭ�� ��� ������������ �з�

	���ڴ� 2���� �迭 board�� 1�� ǥ�õǾ� �ְ�
	board���� ���ڰ� �ż��� ���� 1��,
	���ڰ� ���� ���� 0�� ����

	���ڰ� �ż��� ������ ���� board�� �Ű�������
	�־��� ��, ������ ������ ĭ ����
	return �ϴ� solution �Լ� ����
*/

using namespace std;

bool ChkValidPos(int _r, int _c, int _row, int _col)
{

	if (_r < 0 || _c < 0 || _r >= _row || _c >= _col) return false;
	return true;
}

void ChangeVal(int* _answer, int* _val)
{

	if (*_val != 0) return;

	// *_answer--;
	// ���ϴ� ����� �۵����Ѵ�;
	// �̰� ������ ��û���� Ʋ�ȴ�;
	*_answer = *_answer - 1;
	*_val = 2;
}

int solution(vector<vector<int>> _board)
{

	int answer;

	int row = _board.size();
	int col = _board[0].size();

	answer = row * col;

	for (int r = 0; r < row; r++) 
	{

		for (int c = 0; c < col; c++)
		{

			if (_board[r][c] != 1) continue;

			// �ش� ��ź Ȯ���ߴٰ� ����
			_board[r][c] = 2;
			answer--;

			// �����¿� �������� ���� ��ȿ���� ����
			// 
			if (ChkValidPos(r - 1, c, row, col))
				ChangeVal(&answer, &_board[r - 1][c]);

			if (ChkValidPos(r + 1, c, row, col))
				ChangeVal(&answer, &_board[r + 1][c]);

			if (ChkValidPos(r, c - 1, row, col))
				ChangeVal(&answer, &_board[r][c - 1]);

			if (ChkValidPos(r, c + 1, row, col))
				ChangeVal(&answer, &_board[r][c + 1]);

			// �밢��
			if (ChkValidPos(r - 1, c - 1, row, col))
				ChangeVal(&answer, &_board[r - 1][c - 1]);

			if (ChkValidPos(r - 1, c + 1, row, col))
				ChangeVal(&answer, &_board[r - 1][c + 1]);

			if (ChkValidPos(r + 1, c - 1, row, col))
				ChangeVal(&answer, &_board[r + 1][c - 1]);

			if (ChkValidPos(r + 1, c + 1, row, col))
				ChangeVal(&answer, &_board[r + 1][c + 1]);
		}
	}

	return answer;
}

