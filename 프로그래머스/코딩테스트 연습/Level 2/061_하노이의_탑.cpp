/*
날짜 : 2024. 8. 5
이름 : 배성훈
내용 : 하노이의 탑
	하노이 탑은 퍼즐의 일종이다
	세 개의 기둥과 이 기둥에 꽂을 수 있는 크기가 다양한 원판들이 있고,
	퍼즐을 시작하기 전에는 한 기둥에 원판들이 작은 것이 위에 있도록
	순서대로 쌓여 있다

	게임의 목적은 다 음 두 가지 조건을 만족시키면서,
	한 기둥에 꽂힌 원판들을 그 순서 그대로 다른 기둥으로
	옮겨서 다시 쌓는 것이다

	한 번에 하나의 원판만 옮길 수 있다
	큰 원판이 작은 원판 위에 있어서는 안된다

	하노이 탑의 세 개의 기둥을 왼쪽 부터 1번, 2번, 3번
	1번에는 n개의 원판이 있고,
	이 n개의 원판을 3번 원판으로 최소 횟수로 옮길려고 한다

	1번 기둥에 있는 원판의 개수 n이 매개변수로 주어질 때,
	n개의 원판을 3번 원판으로 최소로 옮기는 방법을
	return 하는 solution 함수 구현

	n은 15 이하의 자연수


	parameter
	2


	return
	{ { 1, 2 }, { 1, 3 }, { 2, 3 } }


	sol

	초기 상태는 다음과 같다
	1번판		2번판		3번판

	 1
	 2

	먼저 1번판의 맨 위에 링을
	2번판으로 옮긴다

	1번판		2번판		3번판
	 
	 
	 2			 1


	이후 1번판의 2를 3번판으로 옮긴다

	1번판		2번판		3번판


				 1			 2

	그리고 2번판의 1을 3번판으로 옮긴다
	1번판		2번판		3번판

							 1
				  			 2
	
	그러면 3회만에 이동된다
	로직을 보면, 1 ~ n번까지의 일렬로 있는 링이 
	i번 판에 이동하는 최소 경우의 수를 an라 하자

	그러면 a(n + 1)은 로직상 1 ~ n를 빈 공간에 이동 시켜야한다
	그래서 an번 이동한다

	그리고 n + 1 링을 i 로 이동시키므로 1번 이동한다
	이후 1 ~n의 링을 i로 이동시켜야 하므로 an번 이동을한다
	그래서 a(n + 1) = 2 x an + 1 이다


*/

#include <vector>

using namespace std;

inline void Move(vector<vector<int>>& _ret, int _from, int _to, int _mid, int _f)
{

	// 현재 원판에 링이 없다
	if (_f == 0) return;

	// 위에 있는 링을
	// 남는 공간으로 옮겨야한다
	Move(_ret, _from, _mid, _to, _f - 1);

	// 링 목적지로 이동
	_ret.push_back({ _from, _to });

	// 위에서 빈 공간에 옮긴 링을
	// 목적지로 옮겨야 한다
	Move(_ret, _mid, _to, _from, _f - 1);
}

vector<vector<int>> solution(int _n)
{

	vector<vector<int>> answer;
	answer.reserve(1 << _n);

	Move(answer, 1, 3, 2, _n);

	return answer;
}