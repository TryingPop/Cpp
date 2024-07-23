/*
날짜 : 2024. 7. 24
이름 : 배성훈
내용 : 숫자 변환하기
	자연수 x를 y로 변환하려고 한다
	사용할 수 있는 연산은 다음과 같다

	x에 n을 더한다
	x에 2를 곱한다
	x에 3을 곱한다

	자연수 x, y, n이 매개변수로 주어질 때,
	x를 y로 변환하기 위해 필요한 최소 연산횟수를
	return 하는 solution 함수 구현

	x를 y로 만들 수 없다면 -1을 return

	parameter
	10, 40, 5


	return
	2


	sol
	10에 2를 곱해 20
	20에 2를 곱해 40
	가는게 최적의 루트다
*/

#include <vector>
#include <queue>

#define NOT_VISIT -1

using namespace std;

inline bool ChkNext(int _next, int _e, const vector<int>& _visit)
{

	/*
	
	방문 안했고 유효한지 확인
	*/
	return (_next <= _e && _visit[_next] == NOT_VISIT);
}

inline int BFS(int _s, int _e, int _add)
{

	/*
	
	s에서 e로 가는 최소 연산 BFS로 찾는다
	*/
	queue<int> q;
	vector<int> visit(_e + 1, NOT_VISIT);

	q.push(_s);
	visit[_s] = 0;

	while (q.size()) 
	{

		int node = q.front();
		q.pop();

		int cur = visit[node];
		int next = node + _add;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}

		next = node * 2;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}

		next = node * 3;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}
	}

	return visit[_e];
}

int solution(int _x, int _y, int _n)
{

	int answer = BFS(_x, _y, _n);

	return answer;
}