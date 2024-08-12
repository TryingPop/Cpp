/*
��¥ : 2024. 8. 12
�̸� : �輺��
���� : ���
	N���� ������ �̷���� ���� �ִ�
	�� ������ �� �������� 1���� N������ ��ȣ�� ���� �ϳ��� �ο��Ǿ� �ִ�
	�� ������ ��������� ������ �� �ִ� ���η� ����Ǿ� �ִµ�,
	���� �ٸ� ���� ���� �̵��� ���� �� ���θ� ������ �Ѵ�
	���θ� ���� �� �ɸ��� �ð��� ���κ��� �ٸ���

	���� 1�� ������ �ִ� ���������� �� ������ ������ ����Ϸ��� �Ѵ�
	�� �����κ��� ���� �ֹ��� �������� �ϴµ�
	N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ����������
	�ֹ��� �������� �Ѵ�

	������ ���� N, �� ������ �����ϴ� ������ ���� road,
	���� ����� ������ �ð� K�� �Ű������� �־��� ��,
	���� �ֹ��� ���� �� �ִ� ������ �ִ� ������
	return �ϴ� solution �Լ��� ����

	������ ���� N�� 50 ������ �ڿ���
	road�� ���̴� 2'000 ������ �ڿ���

	road�� �� ���Ҵ� ������ �����ϰ� �ִ� ���� ������ ��Ÿ����
	road�� �� ���Ҵ� ���̰� 3�� �迭�̸� ������� { a, b, c }���� ��,
	a, b�� ���ΰ� �����ϴ� �� ������ ��ȣ�̰�
	c�� ���θ� �����µ� �ɸ��� �ð��̴�

	�� ���� a, b�� �����ϴ� ���δ� ���� ���� ���� �� �ִ�
	�� ������ ������ ���� �� �ߺ��ؼ� �־����� �ʴ´�

	k�� ���� ����� ������ �ð��� ��Ÿ���� 500'000������ �ڿ���

	������ �� �������� �׻� �̵� ������ ��ΰ� �����Ѵ�

	1�� ������ �ִ� �������� k������ �ð��� ����� ������ ������ ������
	return �ϸ� �ȴ�

	parameter
	5, { { 1, 2, 1 }, { 2, 3, 3 }, { 5, 2, 2 }, { 1, 4, 2 }, { 5, 3, 1 }, { 5, 4, 2 }}, 3


	return
	4


	sol
	1���� 1�� ���� �ִ� �Ÿ��� 0
	1���� 2�� ���� �ִ� �Ÿ��� 1
	1���� 3���� ���� �ִ� �Ÿ��� 1 + 3 = 4
	1���� 4�� ���� �ִ� �Ÿ��� 2
	1���� 5�� ���� �ִ� �Ÿ��� 3

	�̰� �� �߿� 3���ϴ� 1, 2, 4, 5�� �ִ�
	�׷��� 4�̴�
*/

#include <vector>
#include <queue>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

struct MyComp
{

	/*
	
	priority_queue �켱���� ���� ������ ����ü
	-> ���� second�� �������� �������� ���ĵǰ� �ؾ�
	pq���� �������� ������ �ȴ�!
	*/
	bool operator()(pii& _f, pii& _b)
	{

		return _b.second < _f.second;
	}
};

inline void FillEdge(const vector<vector<int>>& _road, vector<vector<pii>>& _edge)
{

	/*
	
	from - to - dis��
	edge[from] = { to, dis } ���°� �ǰ� ����
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
	
	���ͽ�Ʈ�� �˰���
	*/
	priority_queue<pii, vector<pii>, MyComp> pq;
	vector<bool> visit(_n + 1, false);
	vector<int> dis(_n + 1, 1'000'000);

	// ���� ���� �ֱ�
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
	
	��ȯ ���ǿ� �°� ��� ����
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
	
	���ͽ�Ʈ�� ����
	*/
	int answer;

	vector<vector<pii>> edge(_n + 1, vector<pii>());
	FillEdge(_road, edge);
	answer = Dijkstra(_n, edge, _k);

	return answer;
}