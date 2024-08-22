/*
��¥ : 2024. 8. 22
�̸� : �輺��
���� : ü���� �ٽ� ĥ�ϱ�
	������ȣ : 1018��

	���Ʈ���� ������
*/

#include <iostream>
#include <string>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
using namespace std;

inline int ChkMatch(vector<string>& _board, int _r, int _c) 
{

	int ret = 0;
	for (int r = 0; r < 8; r++)
	{

		for (int c = 0; c < 8; c++)
		{

			if ((r + c) & 1) ret += _board[r + _r][c + _c] == 'B';
			else ret += _board[r + _r][c + _c] == 'W';
		}
	}

	ret = Min(ret, 64 - ret);
	return ret;
}

int main(void)
{

	vector<string> board;
	int row, col, ret = 64;
	FAST_IO;

	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{

		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	for (int r = 0; r < row - 7; r++)
	{

		for (int c = 0; c < col - 7; c++)
		{

			ret = Min(ret, ChkMatch(board, r, c));
		}
	}

	cout << ret;
	return 0;
}