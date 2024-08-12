/*
날짜 : 2024. 8. 12
이름 : 배성훈
내용 : 배달
	N개의 마을로 이루어진 나라가 있다
	이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있다
	각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데,
	서로 다른 마을 간에 이동할 때는 이 도로를 지나야 한다
	도로를 지날 때 걸리는 시간은 도로별로 다르다

	현재 1번 마을에 있는 음식점에서 각 마을로 음식을 배달하려고 한다
	각 마을로부터 음식 주문을 받으려고 하는데
	N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만
	주문을 받으려고 한다

	마을의 개수 N, 각 마을을 연결하는 도로의 정보 road,
	음식 배달이 가능한 시간 K가 매개변수로 주어질 때,
	음식 주문을 받을 수 있는 마을의 최대 개수를
	return 하는 solution 함수를 구현

	마을의 개수 N은 50 이하의 자연수
	road의 길이는 2'000 이하의 자연수

	road의 각 원소는 마을을 연결하고 있는 도로 정보를 나타낸다
	road의 각 원소는 길이가 3인 배열이며 순서대로 { a, b, c }라할 때,
	a, b는 도로가 연결하는 두 마을의 번호이고
	c는 도로를 지나는데 걸리는 시간이다

	두 마을 a, b를 연결하는 도로는 여러 개가 있을 수 있다
	한 도로의 정보가 여러 번 중복해서 주어지지 않는다

	k는 음식 배달이 가능한 시간을 나타내며 500'000이하의 자연수

	임의의 두 마을간에 항상 이동 가능한 경로가 존재한다

	1번 마을에 있는 음식점이 k이하의 시간에 배달이 가능한 마을의 개수를
	return 하면 된다

	parameter
	5, { { 1, 2, 1 }, { 2, 3, 3 }, { 5, 2, 2 }, { 1, 4, 2 }, { 5, 3, 1 }, { 5, 4, 2 }}, 3


	return
	4


	sol
	1에서 1로 가는 최단 거리는 0
	1에서 2로 가는 최단 거리는 1
	1에서 3으로 가는 최단 거리는 1 + 3 = 4
	1에서 4로 가는 최단 거리는 2
	1에서 5로 가는 최단 거리는 3

	이고 이 중에 3이하는 1, 2, 4, 5가 있다
	그래서 4이다
*/

#include <vector>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

struct MyComp
{

	/*
	
	priority_queue 우선순위 기준 설정용 구조체
	-> 보면 second를 기준으로 오름차순 정렬되게 해야
	pq에서 내림차순 구현이 된다!
	*/
	bool operator()(pii& _f, pii& _b)
	{

		return _b.second < _f.second;
	}
};

inline void FillEdge(const vector<vector<int>>& _road, vector<vector<pii>>& _edge)
{

	/*
	
	from - to - dis를
	edge[from] = { to, dis } 형태가 되게 저장
	*/
	for (const vector<int>& ele : _road)
	{

		_edge[ele[0]].push_back(mp(ele[1], ele[2]));
		_edge[ele[1]].push_back(mp(ele[0], ele[2]));
	}
}

inline int Dijkstra(const int _n, const vector<vector<pii>>& _edge, const int _k)
{

	/*
	
	다익스트라 알고리즘
	*/
	priority_queue<pii, vector<pii>, MyComp> pq;
	vector<bool> visit(_n + 1, false);
	vector<int> dis(_n + 1, 1'000'000);

	// 시작 지점 넣기
	pq.push(mp(1, 0));
	dis[1] = 0;

	while (!pq.empty())
	{

		pii node = pq.top();
		pq.pop();

		if (visit[node.first]) continue;
		visit[node.first] = true;

		for (const pii& ele : _edge[node.first])
		{

			if (visit[ele.first]) continue;

			int nDis = dis[node.first] + ele.second;

			if (dis[ele.first] <= nDis) continue;
			dis[ele.first] = nDis;
			pq.push(mp(ele.first, nDis));
		}
	}

	/*
	
	반환 조건에 맞게 결과 설정
	*/
	int ret = 0;
	for (int n : dis)
	{

		if (n > _k) continue;
		ret++;
	}

	return ret;
}

int solution(int _n, vector<vector<int>> _road, int _k)
{

	/*
	
	다익스트라 문제
	*/
	int answer;

	vector<vector<pii>> edge(_n + 1, vector<pii>());
	FillEdge(_road, edge);
	answer = Dijkstra(_n, edge, _k);

	return answer;
}