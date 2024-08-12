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
	
	priority_queue�� second ���� �������� �������� ������ �ǰ� 
	�켱���� �Լ��� ������ ����ü
	*/
	bool operator()(pii& _f, pii& _b)
	{

		return _b.second < _f.second;
	}
};

void Dijkstra(vector<vector<pii>>& _edges, 
	vector<int>& _dis, vector<bool>& _visit, int _from)
{

	// �ʱ�ȭ �κ�
	fill(_dis.begin(), _dis.end(), INF);
	fill(_visit.begin(), _visit.end(), false);

	// ���ͽ�Ʈ�� �˰���
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