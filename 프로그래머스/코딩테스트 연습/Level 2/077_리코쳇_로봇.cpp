/*
날짜 : 2024. 8. 21
이름 : 배성훈
내용 : 리코쳇 로봇
	리코쳇 로봇이라는 보드게임이 있다

	이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로,
	시작 위치에서 목표 위치까지 최소 몇 번만에 도달할 수 있는지 말하는 게임이다

	이 게임에서 말의 움직임은 상, 하, 좌, 우 4 방향 중
	하나를 선택해서 게임판 위의 장애물이나 맨 끝에 부딪힐 때까지
	미끄러져 이동하는 것을 한 번의 이동으로 친다

	게임판의 상태를 나타내는 문자열 배열 board가 주어졌을 때,
	말이 목표 위치에 도달하는데 최소 몇 번 이동해야 하는지
	return 하는 solution 함수를 구현

	만약 목표 위치에 도달할 수 없다면 -1을 return

	board의 길이 100 이하 3 이상의 자연수
	board의 원소 길이는 100 이하 3 이상의 자연수
	board의 원소의 길이는 모두 동일하다

	board의 원소에서 "."은 이동 가능한 빈 공간을,
	"D"는이동할 수 없는 장애물을,
	"R"은 시작 위치를,
	"G"는 목표 위치를 나타낸다

	"R", "G"는 한 번씩만 등장한다

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
	아래, 왼쪽, 아래, 왼쪽,
	위, 오른쪽, 위 순서로 이동하면

	목표지점에 도달하고 이게 최선이다
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
	
	유효 범위인지 확인
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(vector<string>& _board)
{

	/*
	
	BFS 세팅과 BFS 진행
	*/

	// 세팅
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

			// 미끄러지는 연산
			for (int i = 0; i <= big; i++)
			{

				int chkR = nextR + dirR[dir];
				int chkC = nextC + dirC[dir];

				// 충돌 시 멈춘다
				if (ChkInvalidPos(chkR, chkC, row, col)
					|| _board[chkR][chkC] == 'D') break;

				nextR += dirR[dir];
				nextC += dirC[dir];
			}

			// 이미 방문했으면 탐색 X
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