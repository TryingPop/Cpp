/*
날짜 : 2024. 9. 14
이름 : 배성훈
내용 : 당구 연습
	프로그래머스의 마스코트인 머쓱이는 최근 취미로 당구를 치기 시작했다

	머쓱이는 손 대신 날개를 사용해야 해서 당구를 잘 못 친다
	하지만 끈기가 강한 머쓱이는 열심히 노력해서 당구를 잘 치려고
	당구 학원에 다니고 있다

	오늘도 당구 학원에 나온 머쓱이에게 당구 선생님이 원쿠션 연습을 하라면서
	당구공의 위치가 담긴 리스트를 건내 줬다
	
	당구에서 공을 쳐서 벽에 맞히는 걸 쿠션이라 부르고,
	벽에 한 번 맞힌 후 공에 맞히면 원쿠션이라 부른다

	리스트에는 머쓱이가 맞춰야 하는 공들의 위치가 담겨 있다
	머쓱이는 리스트에 담긴 각 위치에 순서대로 공을 놓아가며
	원쿠션 연습을 하면 된다
	이때, 머쓱이는 항상 같은 위치에 공을 놓고 쳐서 리스트에 담긴
	위치에 공을 맞춘다

	머쓱이와 달리 최근 취미로 알고리즘 문제를 풀기 시작한 당신은,
	머쓱이가 친 공이 각각의 목표로한 공에 맞을 때까지 최소 얼마의 거리를
	굴러가야 하는지가 궁금해졌습니다

	당구대의 가로 길이 m, 세로 길이 n과 머쓱이가 쳐야 하는 공이 놓인
	위치 좌표를 나타내는 두 정수 startX, startY, 그리고 매 회마다 목표로
	해야하는 공들의 위치 좌표를 나타내는 정수 쌍들이 들어있는 2차원 정수배열
	balls가 주어질 때, 원쿠션 연습을 위해 머쓱이가 공을 적어도
	벽에 한 번은 맞춘 후 목표 공에 맞힌다고 할 때,
	각 회마다 머쓱이가 친 공이 굴러간 거리의 최솟값의 제곱을 배열에 담아
	return 하는 solution 함수를 구현

	단, 머쓱이가 친 공이 벽에 부딪힐 때
	진행방향은 항상 입사각과 반사각이 동일하며,
	만약 꼭짓점에 부딪힐 경우 진입 방향의 반대 방향으로 공이 진행된다
	공의 크기는 무시하며,
	두 공의 좌표가 정확히 일치하는 경우에만 두 공이 서로 맞았다고 판단한다
	공이 목표에 맞기 전에 멈추는 경우는 없으며,
	목표에 맞으면 바로 멈춘다고 가정한다

	m, n은 1000 이하 3 이상인 정수
	startX는 m 이하인 자연수, startY는 n 이하인 자연수
	balls의 길이는 1000 이하이고 2 이상인 자연수
	balls의 원소는 { a, b } 형태이다
	a, b는 머쓱이가 맞춰야할 공이 놓인 좌표를 의미한다

	0 < a < m, 0 < b < n
	(a, b) = (startX, startY)인 입력은 들어오지 않는다


	parameter
	10, 10, 3, 7, { { 7, 7 }, { 2, 7 }, { 7, 3 } }


	return
	{ 52, 37, 116 }


	sol
	7, 7은 y = n에 튕기는게 52로 최소이다
	2, 7도 y = n에 튕기는게 37로 최소이다
	7, 3은 x = 0에 튕기는게 116으로 최소이다
*/

#include <vector>

#define INF 123'456'789
#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))

using namespace std;

inline int GetDis(vector<int>& _f, vector<int>& _t)
{

	/*
	
	거리 제곱 찾기
	*/
	int x = _f[0] - _t[0];
	int y = _f[1] - _t[1];

	return x * x + y * y;
}

inline bool ChkInvalidWall(int _type, vector<int>& _f, vector<int>& _t)
{

	/*
	
	해당 벽에 튕길 수 있는지 확인
	*/
	switch (_type)
	{

	case 0:
		return _t[0] < _f[0] && _f[1] == _t[1];

	case 1:
		return _t[1] < _f[1] && _f[0] == _t[0];

	case 2:
		return _f[0] < _t[0] && _f[1] == _t[1];

	case 3:
		return _f[1] < _t[1] && _f[0] == _t[0];

	default:
		return true;
	}
}

vector<int> solution(int _m, int _n, int _startX, int _startY, vector<vector<int>> _balls)
{

	/*
	
	수학, 브루트 포스
	*/
	vector<int> answer;
	vector<vector<int>> start(4, vector<int>(2));

	start[0] = { -_startX, _startY };
	start[1] = { _startX, -_startY };
	start[2] = { _m - _startX + _m, _startY };
	start[3] = { _startX, _n - _startY + _n };

	vector<int> s = { _startX, _startY };

	for (vector<int>& ball : _balls)
	{

		int dis = INF;

		for (int i = 0; i < 4; i++)
		{

			if (ChkInvalidWall(i, s, ball)) continue;
			int chk = GetDis(start[i], ball);
			dis = Min(dis, chk);
		}

		answer.push_back(dis);
	}

	return answer;
}