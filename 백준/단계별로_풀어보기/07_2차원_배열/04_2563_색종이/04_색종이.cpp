/*
날짜 : 2024. 8. 11
이름 : 배성훈
내용 : 색종이
	문제번호 : 2563번

	구현 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	vector<vector<bool>> board(101, vector<bool>(101, false));
	int n, r, c, ret = 0;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> r >> c;
		for (int i = r; i < r + 10; i++)
		{

			for (int j = c; j < c + 10; j++)
			{

				if (board[i][j]) continue;
				board[i][j] = true;
				ret++;
			}
		}
	}

	cout << ret;
	return 0;
}