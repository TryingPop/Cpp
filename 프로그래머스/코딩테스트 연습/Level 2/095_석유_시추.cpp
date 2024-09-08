/*
날짜 : 2024. 9. 8
이름 : 배성훈
내용 : 석유 시추
	세로 길이가 n, 가로 길이가 m인 격자 모양의 땅 속에서 석유가 발견되었다
	석유는 여러 덩어리로 나누어 묻혀있다

	당신이 시추관을 수직으로 단 하나만 뚫을 수 있을 때,
	가장 많은 석유를 뽑을 수 있는 시추관의 위치를 찾으려고 한다
	시추관은 열 하나를 관통하는 형태여야 하며,
	열과 열 사이에 시추관을 뚫을 수 없다

	시추관은 설치한 위치 아래로 끝까지 뻗어간다
	만약 시추관이 석유 덩어리의 일부를 지나면 해당 덩어리에
	속한 모든 석유를 모두 뽑을 수 있다

	시초관이 뽑을 수 있는 석유량은 시추관이 지나는 
	석유 덩어리들의 크기를 모두 합한 값이다

	석유가 묻힌 땅과 석유 덩어리를 나타내는 
	2차원 정수 배열 land가 매개변수로 주어질 때,
	시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량을
	return 하는 solution 함수 구현

	땅의 세로 길이 = land의 길이는 500이하인 자연수이고
	땅의 가로 길이 land[i]의 길이도 500이하인 자연수이다

	land[i][j]가 0이면 빈 땅을, 1이면 석유가 있는 땅을 의미한다


	parameter
	{ { 0, 0, 0, 1, 1, 1, 0, 0 }, 
	  { 0, 0, 0, 0, 1, 1, 0, 0 }, 
	  { 1, 1, 0, 0, 0, 1, 1, 0 }, 
	  { 1, 1, 1, 0, 0, 0, 0, 0 }, 
	  { 1, 1, 1, 0, 0, 0, 1, 1 } }


	return
	9


	sol
	땅을 보면 다음과 같다
		0	0	0	1	1	1	0	0
		0	0	0	0	1	1	0	0
		1	1	0	0	0	1	1	0
		1	1	1	0	0	0	0	0
		1	1	1	0	0	0	1	1

	석유 덩어리의 무게로 덩어리를 표현하면 
	땅은 다음과 같다
		0	0	0	7	7	7	0	0
		0	0	0	0	7	7	0	0
		8	8	0	0	0	7	7	0
		8	8	8	0	0	0	0	0
		8	8	8	0	0	0	2	2

	이제 시추관을 다음 위치에 꽂으면 
	7 + 2 = 9로 최대가된다
								|
		0	0	0	7	7	7	0	0
		0	0	0	0	7	7	0	0
		8	8	0	0	0	7	7	0
		8	8	8	0	0	0	0	0
		8	8	8	0	0	0	2	2
*/

#include <vector>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

	/*
	
	유효 좌표 확인
	*/
	return _r < 0 || _c < 0 || _r >= _row || _c >= _col;
}

inline int BFS(queue<pii>& _q, vector<vector<int>>& _land, int _g)
{

	/*
	
	인접한 석유 갯수 세기
	*/

	vector<int> dirR = { -1, 0, 1, 0 };
	vector<int> dirC = { 0, -1, 0, 1 };

	int row = _land.size();
	int col = _land[0].size();

	int oil = 1;

	while (_q.size() > 0)
	{

		pii node = _q.front();
		_q.pop();

		for (int i = 0; i < 4; i++)
		{

			int nR = node.first + dirR[i];
			int nC = node.second + dirC[i];

			if (ChkInvalidPos(nR, nC, row, col) || _land[nR][nC] != 1) continue;
			_land[nR][nC] = _g;
			oil++;

			_q.push(mp(nR, nC));
		}
	}

	return oil;
}

inline int GetRet(vector<vector<int>>& _land)
{

	/*
	
	석유 갯수 세고, 시추관 뚫기
	*/

	// 석유 갯수 세기
	queue<pii> q;
	vector<int> oils(2, 0);

	int row = _land.size();
	int col = _land[0].size();

	int g = 1;
	for (int r = 0; r < row; r++)
	{

		for (int c = 0; c < col; c++)
		{

			if (_land[r][c] != 1) continue;
			_land[r][c] = ++g;
			q.push(mp(r, c));
			int oil = BFS(q, _land, g);
			oils.push_back(oil);
		}
	}

	// 시추관 뚫기
	int ret = 0;
	vector<bool> use(oils.size(), false);

	for (int c = 0; c < col; c++)
	{

		for (int r = 0; r < row; r++)
		{

			if (_land[r][c] == 0) continue;
			use[_land[r][c]] = true;
		}

		int chk = 0;
		for (int i = 2; i < use.size(); i++)
		{

			if (!use[i]) continue;
			use[i] = false;
			chk += oils[i];
		}

		ret = Max(chk, ret);
	}

	return ret;
}

int solution(vector<vector<int>> _land)
{

	/*
	
	BFS
	시간 복잡도 O(NM)
	N, M : land 의 행과 열의 크기
	*/
	int answer = GetRet(_land);
	return answer;
}