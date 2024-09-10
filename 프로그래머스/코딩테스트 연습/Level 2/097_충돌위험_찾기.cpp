/*
날짜 : 2024. 9. 10
이름 : 배성훈
내용 : 충돌위험 찾기
	어떤 물류 센터는 로봇을 이용한 자동 운송 시스템을 운영한다
	운송 시스템이 작동하는 규칙은 다음과 같다

	1. 물류 센터에는 r,c와 같이 2차원 좌표로 
	나타낼 수 있는 n개의 포인트가 존재한다
	각 포인트는 1 ~ n으로 서로 다른 번호를 갖는다

	2. 로봇마다 정해진 운송 경로가 존재한다
	운송 경로는 m개의 포인트로 구성되고
	로봇은 첫 포인트에서 시작해 할당된 포인트를 순서대로 방문한다

	3. 운송 시스템에 사용되는 로봇은 x 대이고,
	모든 로봇은 0초에 동시에 출발한다
	로봇은 1초마다 r좌표와 c좌표 중 하나가 1만큼 감소하거나
	증가한 좌표로 이동할 수 있다

	4. 다음 포인트로 이동할 때는 항상 최단 경로로 이동하며
	최단 경로가 여러 가지일 경우, r좌표가 변하는 이동을
	c좌표가 변하는 이동보다 먼저 한다

	5. 마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어난다
	로봇이 물류 센터를 벗어나는 경로는 고려하지 않는다

	이동 중 같은 좌표에 로봇이 2대 이상 모인다면 충돌할 가능성이 있는
	위험 상황으로 판단한다

	관리자인 당신은 현재 설정대로 로봇을 움직일 때 위험한 상황이 
	총 몇 번 일어나는지 알고 싶다
	만약 어떤 시간에 여러 좌표에서 위험 상황이 발생한다면 
	그 횟수를 모두 더한다

	운송 포인트 n개의 좌표를 담은 2차원 정수 배열 points와 
	로봇 x대의 운성 경로를 담은 2차원 정수 배열 routes가 매개변수로 주어질 때,
	모든 로봇이 운송을 마칠 때까지 발생하는 위험한 상황을 횟수를
	return 하는 solution 함수 구현

	points의 길이는 100 이하 2 이상의 자연수

	points[i]는 i + 1 번 포인트의 { r좌표, c좌표 }를 나타내는
	길이가 2인 정수 배열이다
	r, c 는 100 이하의 자연수
	같은 좌표에 여러 포인트가 존재하는 입력은 없다

	routes의 길이는 로봇의 수와 같고 100 이하 2 이상의 자연수이다
	routes[i]의 길이도 100 이하 2 이상의 자연수이고,
	i + 1 번째 로봇의 운송경로를 나타낸다
	routes[i]는 모두 같다

	routes[i][j]는 n보다 작고
	같은 포인트를 연속으로 방문하는 입력은 주어지지 않는다

	
	parameter
	{ { 3, 2 }, { 6, 4 }, { 4, 7 }, { 1, 4 } },
	{ { 4, 2 }, { 1, 3 }, { 2, 4 } }


	return
	1


	sol
	3초 후 { 4, 4 }의 좌표에서 1, 2의 충돌이 1번 일어난다
	이외는 충돌이 일어나지 않는다
*/

#include <vector>

using namespace std;

inline void Move(vector<int>& _pos, vector<int>& _goal)
{

	/*
	
	이동
	pos와 goal이 다른 경우만 와야한다
	*/
	if (_pos[0] < _goal[0]) _pos[0]++;
	else if (_pos[0] > _goal[0]) _pos[0]--;
	else if (_pos[1] < _goal[1]) _pos[1]++;
	else _pos[1]--;
}

inline bool IsGoal(vector<int>& _pos, vector<int>& _goal)
{

	/*
	
	목적지 도달 확인
	*/
	return _pos[0] == _goal[0] && _pos[1] == _goal[1];
}

inline int CntCollision(vector<vector<int>>& _robot, vector<vector<int>>& _map)
{

	/*
	
	충돌 지점 확인
	*/

	int ret = 0;
	for (int i = 0; i < _robot.size(); i++)
	{

		if (_map[_robot[i][0]][_robot[i][1]] > 1) ret++;
		_map[_robot[i][0]][_robot[i][1]] = 0;
	}

	return ret;
}

inline int Simulation(vector<vector<int>>& _points, vector<vector<int>>& _routes)
{

	/*
	
	시뮬레이션
	*/

	// 초기 세팅
	int ret = 0;

	vector<vector<int>> map(101, vector<int>(101, 0));
	vector<int> idxs(_routes.size(), 1);

	vector<vector<int>> robot;
	robot.reserve(_routes.size());

	for (int i = 0; i < _routes.size(); i++)
	{

		robot.push_back(_points[_routes[i][0] - 1]);
		map[robot[i][0]][robot[i][1]]++;
	}

	ret += CntCollision(robot, map);
	
	// 시뮬레이션
	while (true)
	{

		bool flag = true;
		for (int i = 0; i < robot.size(); i++)
		{

			int& idx = idxs[i];
			if (idx == 0) continue;

			if (IsGoal(robot[i], _points[_routes[i][idx] - 1])) 
			{

				idx++;
				if (idx == _routes[i].size())
				{

					idx = 0;
					continue;
				}
			}

			flag = false;
			Move(robot[i], _points[_routes[i][idx] - 1]);
			map[robot[i][0]][robot[i][1]]++;
		}

		if (flag) break;

		ret += CntCollision(robot, map);
	}

	return ret;
}

int solution(vector<vector<int>> _points, vector<vector<int>> _routes)
{

	/*

	시뮬레이션
	로봇의 개수 A(100), 맵의 최대 택시 거리 B(200), routes의 길이 C(100)
	시간 복잡도 O(A x B x C)
	*/
	int answer = Simulation(_points, _routes);
	return answer;
}