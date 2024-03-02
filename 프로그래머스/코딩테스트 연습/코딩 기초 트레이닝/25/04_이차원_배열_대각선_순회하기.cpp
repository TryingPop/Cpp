#include <vector>

/*
날짜 : 2024. 3. 2
이름 : 배성훈
내용 : 이차원 배열 대각선 순회하기
	2차원 정수 배열 board와 k가 주어진다

	i + j <= k를 만족하는 모든 i, j에 대해
	board[i][j]의 합을 return하는 solution 함수 구현

	모든 board[i]의 크기는 같다
*/

using namespace std;

int solution(vector<vector<int>> _board, int _k)
{

	int answer = 0;

	int r = _board.size();
	int c = _board[0].size();

	for (int i = 0; i < r; i++)
	{

		for (int j = 0; j < c; j++)
		{

			if (i + j > _k) break;
			answer += _board[i][j];
		}
	}

	return answer;
}