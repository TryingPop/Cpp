#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define mp make_pair

#define INF 1e9
using namespace std;

struct MyComp 
{

	/*
	
	priority_queue에 second 값을 기준으로 오름차순 정렬이 되게 
	우선순위 함수를 정의한 구조체
	*/
	bool operator()(pii& _f, pii& _b)
	{

		return _b.second < _f.second;
	}
};

void Dijkstra(vector<vector<pii>>& _edges, 
	vector<int>& _dis, vector<bool>& _visit, int _from)
{

	// 초기화 부분
	fill(_dis.begin(), _dis.end(), INF);
	fill(_visit.begin(), _visit.end(), false);

	// 다익스트라 알고리즘
	priority_queue<pii, vector<pii>, MyComp> pq;

	pq.push(mp(_from, 0));
	_dis[_from] = 0;

	while (!pq.empty())
	{

		int node = pq.top().first;
		pq.pop();

		if (_visit[node]) continue;
		_visit[node] = true;

		for (const pii& edge : _edges[node])
		{

			if (_visit[edge.first]) continue;

			int nDis = _dis[node] + edge.second;

			if (_dis[edge.first] <= nDis) continue;

			_dis[edge.first] = nDis;
			pq.push(mp(edge.first, nDis));
		}
	}
}