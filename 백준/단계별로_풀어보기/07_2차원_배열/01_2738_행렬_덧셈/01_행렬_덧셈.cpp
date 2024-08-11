/*
날짜 : 2024. 8. 11
이름 : 배성훈
내용 : 행렬 덧셈
	문제번호 : 2738번
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
#define endl	'\n'
using namespace std;

inline void FillMat(vector<vector<int>>& _mat, int _row, int _col)
{

	for (int r = 0; r < _row; r++)
	{

		for (int c = 0; c < _col; c++)
		{

			cin >> _mat[r][c];
		}
	}
}

int main(void)
{

	int row, col;
	vector<vector<int>> a, b;

	FAST_IO;
	
	cin >> row >> col;

	a.resize(row, vector<int>(col));
	b.resize(row, vector<int>(col));

	FillMat(a, row, col);
	FillMat(b, row, col);

	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			cout << a[r][c] + b[r][c] << EMPTY;
		}

		cout << endl;
	}

	return 0;
}