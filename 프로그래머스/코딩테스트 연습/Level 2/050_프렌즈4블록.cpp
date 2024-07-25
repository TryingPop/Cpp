/*
날짜 : 2024. 7. 25
이름 : 배성훈
내용 : 프렌즈4블록
	같은 모양의 블록이 2 x 2 형태로 4개가 붙어있을 경우 사라지면서
	점수를 얻는 게임이다

	2 x 2로 배치된 블록이 여러 개가 있으면,
	한꺼번에 지워진다

	블록이 지워진 후에 위에 있는 블록이 아래로 떨어져
	빈 공간을 채우게 된다

	만약 빈 공간을 채운 후에 다시 2x2형태로
	같은 모양의 블록이 모이면 다시 지워지고
	떨어지고를 반복하게 된다

	입력으로 블록의 첫 배치가 주어졌을 때,
	지워지는 블록은 모두 몇 개인지 판단하는 프로그램을 제작해라

	입력으로 판의 높이 m, 폭 n과 판의 배치 정보 board가 들어온다
	n, m 은 2이상 30이하의 정수

	board는 길이 n인 문자열 m개의 배열로 주어진다
	블록을 나타내는 문자는 A에서 Z가 사용된다

	입력으로 주어진 판의 정보를 가지고 
	몇 개의 블록이 지워질지 출력

	parameter
	4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }


	return
	14


	sol
	CCBDE
	AAADE
	AAABF
	CCBBF

	모양인데
	A 2 x 2 블록이 2개 있다
	이를 제거하면

	CCBDE
	   DE
	   BF
	CCBBF

	가되고
	여기서 CCB 블록이 내려온다

	   DE
	   DE
	CCBBF
	CCBBF
	그리고 다시 2 x 2 블록을 판정하면
	C, B가 있다

	이들을 제거하면

	   DE
	   DE
	    F
		F

	가되고
	다시 블록을 내리면

	    E
		E
	   DF
	   DF
	가된다

	더 이상 2 x 2 블록은 없고
	제거된 블록은 14개이다
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
	
	블록 부수기 및 부순 블록 개수 반환하는 함수
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
	
	블록 아래로 내리기
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
	
	2 x 2 블록 찾기
	비워진 공간을 제외하고 적어도 1개 존재 true
	없으면 false
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