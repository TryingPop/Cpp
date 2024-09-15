/*
날짜 : 2024. 9. 15
이름 : 배성훈
내용 : 도넛과 막대 그래프
	도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프들이 있다
	이 그래프들은 1개 이상의 정점과, 정점들을 연결하는 단방향 간선으로 이루어져 있다

	크기가 n인 도넛 모양의 그래프는 n개의 정점과 n개의 간서닝 있다
	도넛 모양 그래프의 아무 한 정점에서 출발해 이용한 적 없는 간선을
	계속 따라가면 나머지 n - 1개의 정점들을 한 번씩 방문한 뒤 
	원래 출발했던 정점으로 돌아오게 된다

	크기가 n인 막대 모양 그래프는 n개의 정점과 n - 1개의 간선이 있다
	막대 모양 그래프는 임의의 한 정점에서 출발해 
	간선을 계속 따라가면 나머지 n - 1개의 정점을 한 번씩 방문되는
	정점이 단 하나 존재한다

	크기가 n인 8자 모양 그래프는 2n + 1개의 정점과 
	2n + 2의 간선이 있다
	8자 모양 그래프는 크기가 동일한 2개의 도넛 모양 그래프에서 정점을
	하나씩 골라 결합시킨 형태의 그래프이다

	도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프가 여러 개 있다
	이 그래프들과 무관한 정점을 하나 생성한 뒤,
	각 도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의
	임의의 정점 하나로 향하는 간선들을 연결했다

	그 후 각 정점에 서로 다른 번호를 매겼다

	이때 당신은 그래프의 간선 정보가 주어지면 생성한 정점의 번호와
	정점을 생성하기 전 도넛 모양 그래프의 수, 막대 모양 그래프의 수,
	8자 모양 그래프의 수를 구해야 한다

	그래프의 간선 정보를 담은 2차원 정수 배열 edges가 매개변수로 주어질 때
	생성한 정점의 번호, 도넛 모양 그래프의 수,
	막대 모양 그래프의 수, 8자 모양 그래프의 수를 순서대로 1차원 정수 배열에 담아
	return 하는 solution 함수 구현

	edges의 길이 100만 이하인 자연수이다
	edges의 원소는 { a, b }의 형태이며
	a번 정점에서 b번 정점으로 향하는 간선이 있다는 것을 나타낸다

	a, b는 100만 이하의 자연수다

	문제 조건에 맞는 그래프만 주어진다

	도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 수의 합은 2 이상이다


	parameter
	{ { 2, 3 }, { 4, 3 }, { 1, 1 }, { 2, 1 } }


	return
	{ 2, 1, 1, 0 }
*/

#include <vector>

#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

int len;
vector<int> fd, td, go;
vector<bool> visit;

inline void SetLen(vector<vector<int>>& _edges)
{

	/*
	
	노드의 최대 번호 찾기 및 배열들 초기화
	*/

	for (vector<int>& edge : _edges)
	{

		len = Max(len, edge[0]);
		len = Max(len, edge[1]);
	}

	fd.resize(len + 1, 0);
	td.resize(len + 1, 0);
	go.resize(len + 1, 0);
	visit.resize(len + 1, false);
}

inline int GetStart(vector<vector<int>>& _edges)
{

	/*
	
	위상 정렬 방식으로 시작지점을 찾는다
	*/
	for (vector<int>& edge : _edges)
	{

		fd[edge[0]]++;
		td[edge[1]]++;

		go[edge[0]] = edge[1];
	}

	for (int i = 1; i <= len; i++)
	{

		if (td[i]) continue;
		else if (1 < fd[i]) return i;
	}

	return -1;
}

inline void GetRet(int _s, vector<int>& _ret, vector<vector<int>>& _edges)
{

	/*
	
	그래프 찾기
	방문한 곳으로 오지 못하면 막대 모양
	방문한 곳으로 오는데 중간에 간선이 2개 이상인 경우는 8자
	이외는 도넛 모양
	*/

	_ret.resize(4, 0);
	_ret[0] = _s;

	for (vector<int>& edge : _edges)
	{

		if (edge[0] != _s) continue;
		int cur = edge[1];

		while (true)
		{

			if (fd[cur] == 2)
			{

				_ret[3]++;
				break;
			}
			else if (fd[cur] == 0) 
			{

				_ret[2]++;
				break;
			}

			visit[cur] = true;
			cur = go[cur];
			if (visit[cur])
			{

				_ret[1]++;
				break;
			}
		}
	}
}

vector<int> solution(vector<vector<int>> _edges)
{

	/*
	
	그래프 문제
	*/
	vector<int> answer;
	SetLen(_edges);

	int gen = GetStart(_edges);

	GetRet(gen, answer, _edges);
	return answer;
}