/*
날짜 : 2024. 8. 23
이름 : 배성훈
내용 : 가장 큰 정사각형 찾기
	1과 0으로 채워진 표(board)가 있다
	표 1칸은 1 x 1의 정 사각형으로 이루어져 있다
	표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를
	return 하는 solution 함수를 구현

	표(board)는 2차원 배열로 주어진다
	표(board)의 행(row)과 열(column)의 크기는 1'000 이하의 자연수
	표(board)의 값은 1 또는 0으로만 이루어져 있다

	
	parameter
	{ { 0, 1, 1, 1 },
	  { 1, 1, 1, 1 }, 
	  { 1, 1, 1, 1 }, 
	  { 0, 0, 1, 0 } }


	return
	9


	sol
	맵을 보면 4 x 4 이고 숫자는 다음과 같다
		0	1	1	1
		1	1	1	1
		1	1	1	1
		0	0	1	0
	왼쪽 위 끝점이 0이라 4 x 4 정사각형은 불가능하고

		0  |1	1	1|
		1  |1	1	1|
		1  |1	1	1|

		0	0	1	0
	다음과 같은 3 x 3 정사각형이 존재해
	최대는 3 x 3 정사각형이다
*/

#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline void SetDp(vector<vector<int>>& _board, vector<vector<int>>& _dp)
{

	/*
	
	dp[r][c] : r, c 를 오른쪽 아래 점으로 하는 
		가장 큰 정사각형의 길이를 값으로 갖는다

	a	b
	c	x

	x에서 만들 수 있는 가장 큰 정사각형은
	x의 좌표가 0이면 0이다

	x의 좌표가 0이 아닌 경우
	a, b, c 에서 만들 수 있는 가장 큰 정사각형 중 가장 작은거에 + 1한 값이다
	c는 x의 가로선 부분을 보장해주고,
	b는 x의 세로선 부분을 보장해준다
	a는 x의 왼쪽 위 부분을 보장해주기 때문이다
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
	
	dp의 최대값을 찾고 넓이 형태로 변형
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
	
	dp 문제
	*/

	int row = _board.size();
	int col = _board[0].size();

	vector<vector<int>> dp(row, vector<int>(col, 0));

	SetDp(_board, dp);
	int answer = GetRet(dp);
	return answer;
}