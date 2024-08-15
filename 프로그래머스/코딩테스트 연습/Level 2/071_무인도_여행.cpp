/*
날짜 : 2024. 8. 15
이름 : 배성훈
내용 : 무인도 여행
	지도에는 바다와 1x1 크기의 사각형들로 이루어진 
	직사각형 격자의 형태이며,

	격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀 있다
	지도의 'X'는 바다를 나타내며,

	숫자는 무인도를 나타낸다
	이때 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룬다

	지도의 각 칸에 적힌 숫자는 식량을 나타내는데,
	상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은
	해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타낸다

	어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서
	최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 한다

	지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때,
	각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아
	return 하는 solution 함수 구현

	만약 지낼 수 있는 무인도가 없다면 -1을 return

	maps의 길이는 100 이하 3이상의 정수,
	maps[i]의 길이도 100이하 3이상의 정수이고
	maps[i]는 'X' 또는 1과 9 사이의 자연수로 이루어진 문자열이다
	지도는 직사각형 형태다


	parameter
	{ "X591X","X1X5X","X231X", "1XXX1" }


	return
	{ 1, 1, 27 }


	sol
	지도를 보면 다음처럼 무인도 영역이 나뉜다
		X|	5	9	1  |X
		X|	1	X	5  |X
		X|	2	3	1  |X
		-----------------
		1|	X	X	X  |1

	각 무인도에서 생존할 수 있는 날짜는 숫자의 합이므로
	27, 1, 1 이 있고 이를 오름차순 정렬하면
	1, 1, 27이된다
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define mp make_pair
#define pii pair<int, int>

using namespace std;

inline bool ChkInvalidPos(const int _r, const int _c, const int _row, const int _col)
{

	/*
	
	유효한 인덱스인지 판별
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int GetDay(vector<string>& _maps, queue<pii>& _q)
{

	/*
	
	해당 무인도에서 생존할 수 있는 날짜 계산
	*/
	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	int row = _maps.size();
	int col = _maps[0].size();

	int ret = 0;

	while (_q.size())
	{

		pii node = _q.front();
		_q.pop();

		for (int i = 0; i < 4; i++)
		{

			int nextR = node.first + dirR[i];
			int nextC = node.second + dirC[i];

			if (ChkInvalidPos(nextR, nextC, row, col)
				|| _maps[nextR][nextC] == 'X') continue;

			ret += _maps[nextR][nextC] - '0';
			_maps[nextR][nextC] = 'X';

			_q.push(mp(nextR, nextC));
		}
	}

	return ret;
}

vector<int> solution(vector<string> _maps)
{

	/*
	
	BFS
	*/
	vector<int> answer;
	
	int row = _maps.size();
	int col = _maps[0].size();

	queue<pii> q;

	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_maps[r][c] == 'X') continue;

			int day = _maps[r][c] - '0';
			_maps[r][c] = 'X';

			q.push(mp(r, c));
			day += GetDay(_maps, q);
			answer.push_back(day);
		}
	}

	if (answer.empty()) answer.push_back(-1);
	else sort(answer.begin(), answer.end());

	return answer;
}