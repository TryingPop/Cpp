/*
날짜 : 2024. 8. 17
이름 : 배성훈
내용 : 미로 탈출
	1 x 1 크기의 칸들로 이루어진 
	직사각형 격자 형태의 미로에서 탈출하려고 한다

	각 칸은 통로 또는 벽으로 구성되어 있으며,
	벽으로 된 칸은 지나갈 수 없고
	통로로 된 칸으로만 이동할 수 있다

	통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데,
	이 문은 레버를 당겨서만 열 수 있다
	레버 또한 통로들 중 한 칸에 있다
	따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여
	레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 된다

	이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있다
	미로에서 한 칸을 이동하는데 1초가 걸린다고 할 때,
	최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 한다

	미로를 나타낸 문자열 배열 maps가 매개변수로 주어질 때
	미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 구현
	만약 탈출할 수 없다면 -1을 return

	maps의 길이는 5 이상 100 이하의 자연수

	maps[i]의 길이는 5 이상 100 이하의 자연수

	maps[i]는 다음 5개의 문자들로 이루어져 있다
	S : 시작지점, E : 출구, L : 레버, O : 통로, X : 벽

	시작지점과 출구, 레버는 항상 다른 곳에 존재하며 1개씩만 존재한다

	출구는 레버가 당겨지지 않아도 지나갈 수 있으며,
	모든 통로 출구, 레버, 시작 지점은 여러번 지나갈 수 있다

	parameter
	{ "SOOOL",
	  "XXXXO",
	  "OOOOO",
	  "OXXXX",
	  "OOOOE" }


	return
	16


	sol
	미로가 다음과 같이 있다
		S	O	O	O	L
		X	X	X	X	O
		O	O	O	O	O
		O	X	X	X	X
		O	O	O	O	E

	이동 칸수를 다음과 같이 표기하면
		0	1	2	3	4
		X	X	X	X	5
	   10	9	8	7	6
	   11	X	X	X	X
	   12  13  14  15  16

	순서로 이동하면 4에서 레버를 열고
	도착지점에 도달하는 결과가 된다
*/

#include <string>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

struct Pos
{

	/*
	
	BFS 탐색에 쓸 좌표
	*/
	int r;			// 행 = y
	int c;			// 열 = x
	bool key;		// 레버 당긴 여부

public:
	Pos(bool _key, int _r, int _c)
		: key(_key), r(_r), c(_c) { }
};

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

	/*
	
	좌표가 맵을 벗어났는지 확인
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(vector<string>& _maps)
{

	/*
	
	BFS
	*/
	int row = _maps.size();
	int col = _maps[0].size();

	// 레버 당긴 여부, 현재 y, 현재 x에 도달하는데 최소 값을 담는다
	vector<vector<vector<int>>> move(2, vector<vector<int>>(row, vector<int>(col, -1)));

	queue<Pos> q;
	pii e;

	// 시작지점과 끝 지점 찾기
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_maps[r][c] == 'S')
			{

				q.push(Pos(false, r, c));
				move[0][r][c] = 0;
			}
			else if (_maps[r][c] == 'E') e = mp(r, c);
		}
	}

	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	while (q.size())
	{

		Pos node = q.front();
		q.pop();

		int cur = move[node.key][node.r][node.c];

		for (int i = 0; i < 4; i++)
		{

			int nextR = node.r + dirR[i];
			int nextC = node.c + dirC[i];

			if (ChkInvalidPos(nextR, nextC, row, col)
				|| _maps[nextR][nextC] == 'X') continue;

			// 레버 당겼는지 확인
			bool key = node.key || _maps[nextR][nextC] == 'L';

			// 이미 방문?
			if (move[key][nextR][nextC] != -1) continue;

			// 방문 안했으므로 해당 장소로 이동 가능
			move[key][nextR][nextC] = cur + 1;
			q.push(Pos(key, nextR, nextC));
		}
	}

	return move[1][e.first][e.second];
}

int solution(vector<string> _maps)
{

	/*
	
	BFS 문제
	*/
	int answer = BFS(_maps);
	return answer;
}