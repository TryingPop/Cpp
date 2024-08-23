/*
��¥ : 2024. 8. 23
�̸� : �輺��
���� : ���� ū ���簢�� ã��
	1�� 0���� ä���� ǥ(board)�� �ִ�
	ǥ 1ĭ�� 1 x 1�� �� �簢������ �̷���� �ִ�
	ǥ���� 1�� �̷���� ���� ū ���簢���� ã�� ���̸�
	return �ϴ� solution �Լ��� ����

	ǥ(board)�� 2���� �迭�� �־�����
	ǥ(board)�� ��(row)�� ��(column)�� ũ��� 1'000 ������ �ڿ���
	ǥ(board)�� ���� 1 �Ǵ� 0���θ� �̷���� �ִ�

	
	parameter
	{ { 0, 1, 1, 1 },
	  { 1, 1, 1, 1 }, 
	  { 1, 1, 1, 1 }, 
	  { 0, 0, 1, 0 } }


	return
	9


	sol
	���� ���� 4 x 4 �̰� ���ڴ� ������ ����
		0	1	1	1
		1	1	1	1
		1	1	1	1
		0	0	1	0
	���� �� ������ 0�̶� 4 x 4 ���簢���� �Ұ����ϰ�

		0  |1	1	1|
		1  |1	1	1|
		1  |1	1	1|

		0	0	1	0
	������ ���� 3 x 3 ���簢���� ������
	�ִ�� 3 x 3 ���簢���̴�
*/

#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline void SetDp(vector<vector<int>>& _board, vector<vector<int>>& _dp)
{

	/*
	
	dp[r][c] : r, c �� ������ �Ʒ� ������ �ϴ� 
		���� ū ���簢���� ���̸� ������ ���´�

	a	b
	c	x

	x���� ���� �� �ִ� ���� ū ���簢����
	x�� ��ǥ�� 0�̸� 0�̴�

	x�� ��ǥ�� 0�� �ƴ� ���
	a, b, c ���� ���� �� �ִ� ���� ū ���簢�� �� ���� �����ſ� + 1�� ���̴�
	c�� x�� ���μ� �κ��� �������ְ�,
	b�� x�� ���μ� �κ��� �������ش�
	a�� x�� ���� �� �κ��� �������ֱ� �����̴�
	*/

	int row = _board.size();
	int col = _board[0].size();

	for (int c = 0; c < col; c++)
	{

		_dp[0][c] = _board[0][c];
	}

	for (int r = 1; r < row; r++)
	{

		_dp[r][0] = _board[r][0];
	}

	for (int r = 1; r < row; r++)
	{

		for (int c = 1; c < col; c++)
		{

			if (_board[r][c] == 0) continue;
			_dp[r][c] = Min(_dp[r - 1][c], _dp[r][c - 1]);
			_dp[r][c] = Min(_dp[r][c], _dp[r - 1][c - 1]);
			_dp[r][c]++;
		}
	}
}

int GetRet(vector<vector<int>>& _dp) 
{

	/*
	
	dp�� �ִ밪�� ã�� ���� ���·� ����
	*/
	int row = _dp.size();
	int col = _dp[0].size();

	int ret = 0;
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			ret = Max(ret, _dp[r][c]);
		}
	}

	return ret * ret;
}

int solution(vector<vector<int>> _board)
{

	/*
	
	dp ����
	*/

	int row = _board.size();
	int col = _board[0].size();

	vector<vector<int>> dp(row, vector<int>(col, 0));

	SetDp(_board, dp);
	int answer = GetRet(dp);
	return answer;
}