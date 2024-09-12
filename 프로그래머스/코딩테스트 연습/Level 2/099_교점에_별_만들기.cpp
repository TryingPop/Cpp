/*
날짜 : 2024. 9. 12
이름 : 배성훈
내용 : 교점에 별 만들기
	Ax + By + C = 0 으로 표현할 수 있는
	n개의 직선이 주어질 때,

	이 직선의 교점 중 정수 좌표에 별을 그리려 한다

	직선 A, B, C에 대한 정보가 담긴 배열 line이 매개변수로 주어질 때,
	이때 모든 별을 포함하는 최소 사각형을 return 하는 solution 함수 구현

	line의 행의 길이는 1000이하 2이상인 자연수
	line의 열의 길이는 3으로 고정되어 있고 { A, B, C } 형태다
	A, B, C는 -10만 이상이고 10만 이하인 정수이다
	A = 0이면서 B = 0인 경우는 주어지지 않는다

	정답은 1000 x 1000 크기 내에서 표현된다
	별이 한 개 이상 그려지는 입력만 주어진다

	parameter
	{ { 2, -1, 4 }, { -2, -1, 4 }, { 0, -1, 1 }, { 5, -8, -12 }, { 5, 8, 12 } }

	
	return
	{ "....*....", 
	  ".........", 
	  ".........", 
	  "*.......*", 
	  ".........", 
	  ".........", 
	  ".........", 
	  ".........", 
	  "*.......*" }


	sol
	만나는 정수 좌표인 교점들을 모두 구하면
	(0, 4), (-4, 1), (4, 1), (-4, -4), (4, 4)
	이다 이를 표현하면 정답처럼 된다
*/

#include <vector>
#include <string>
#include <utility>

#define ll long long

#define pll pair<ll, ll>
#define mp make_pair

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline bool NotMeetLine(vector<int>& _f, vector<int>& _g)
{

	/*
	
	직선끼리 평행한지 확인
	*/
	return _f[0] * _g[1] == _f[1] * _g[0];
}

inline bool NotMeetPos(vector<int>& _f, ll _x, ll _y)
{

	/*
	
	점이 직선위에 있는지 확인
	*/
	return _f[0] * _x + _f[1] * _y + _f[2] != 0;
}

inline void GetMeetPos(vector<vector<int>>& _line, vector<pll>& _meet)
{

	/*
	
	직선들간 만나는 정수좌표 구해 meet에 담는다
	*/
	for (int i = 1; i < _line.size(); i++)
	{

		vector<int>& f = _line[i];

		for (int j = 0; j < i; j++)
		{

			if (NotMeetLine(_line[i], _line[j])) continue;
			vector<int>& g = _line[j];

			ll bot = (1LL * f[1] * g[0] - 1LL * g[1] * f[0]);

			ll gx = (1LL * f[2] * g[1] - 1LL * f[1] * g[2]) / bot;
			ll gy = (1LL * f[0] * g[2] - 1LL * f[2] * g[0]) / bot;

			if (NotMeetPos(f, gx, gy)
				|| NotMeetPos(g, gx, gy)) continue;

			_meet.push_back(mp(gx, gy));
		}
	}
}

inline void DrawMap(vector<string>& _map, vector<pll>& _meet)
{

	/*
	
	최소사이즈인 정답 구하기
	*/
	ll minX = 1e15, minY = 1e15, maxX = -1e15, maxY = -1e15;

	for (pll& pos : _meet)
	{

		minX = Min(minX, pos.first);
		maxX = Max(maxX, pos.first);

		minY = Min(minY, pos.second);
		maxY = Max(maxY, pos.second);
	}

	string temp(maxX - minX + 1, '.');
	_map.resize(maxY - minY + 1, temp);

	for (pll& pos : _meet)
	{

		ll x = pos.first - minX;
		ll y = maxY - pos.second;

		_map[y][x] = '*';
	}
}

vector<string> solution(vector<vector<int>> _line)
{

	/*
	
	수학 문제
	*/
	vector<string> answer;
	vector<pll> meet;

	GetMeetPos(_line, meet);
	DrawMap(answer, meet);
	return answer;
}