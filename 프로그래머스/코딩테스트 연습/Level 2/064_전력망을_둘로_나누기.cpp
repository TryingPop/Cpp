/*
날짜 : 2024. 8. 8
이름 : 배성훈
내용 : 전력망을 둘로 나누기
	n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결
	이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할
	두 전력망이 갖게되는 송전탑의 개수를 최대한 비슷하게 맞추고자 한다

	송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어질 때,
	전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록
	두 전력망으로 나누었을 때,
	두 전력망이 가지고 있는 송전탑 개수의 차이를 
	return 하는 solution 함수 구현

	n은 2이상 100이하의 자연수
	wires는 길이가 n - 1인 2차원 배열
	wires의 각 원소는 2개로 이루어진 { v1, v2 } 이며 v1, v2는 자연수이고
	v1과 v2가 전선으로 연결되어 있음을 의미한다
	v1, v2는 n이하의 자연수이다
	wires는 트리가 아닌 경우는 주어지지 않는다


	parameter
	9, { { 1, 3 },{ 2, 3 },{ 3, 4 },{ 4, 5 },{ 4, 6 },{ 4, 7 },{ 7, 8 },{ 7, 9 } }


	return
	3


	sol
	그래프는 다음과 같은 형태인데	
		1	5	8
		|	|	|
		3 - 4 - 7
		|	|	|
		2	6	9
	
	3에서 4로 가는 간선을 끊는 경우
	1, 2, 3 그룹1과, 
	4, 5, 6, 7, 8, 9 그룹 2로 나뉘고

	이 때 두 그룹의 차가 최소 중 하나이다
*/

#include <algorithm>
#include <vector>

#define ABS(X)	((X < 0) ? -(X) : (X));
using namespace std;

inline void SetLine(const vector<vector<int>>& _wires, vector<vector<int>>& _ret) 
{

	for (const vector<int>& cur : _wires)
	{

		_ret[cur[0]].push_back(cur[1]);
		_ret[cur[1]].push_back(cur[0]);
	}
}

#if first
inline bool ChkDisConn(const int _n1, const int _n2, const int _not1, const int _not2)
{

	/*
	
	끊어진 간선인지 확인
	*/
	if ((_n1 == _not1 && _n2 == _not2)
		|| (_n1 == _not2 && _n2 == _not1)) return true;

	return false;
}

inline int DFS(int _f, vector<bool>& _visit, const vector<vector<int>>& _line, const int _not1, const int _not2)
{

	/*
	
	연결된 노드들 개수 확인
	*/
	int ret = 1;

	for (int t : _line[_f])
	{

		if (_visit[t] || ChkDisConn(_f, t, _not1, _not2)) continue;
		_visit[t] = true;

		ret += DFS(t, _visit, _line, _not1, _not2);
	}

	return ret;
}

#else

inline void DFS(int _f, int _parent, vector<int>& _size, const vector<vector<int>>& _line)
{

	if (_size[_f]) return;
	_size[_f] = 1;

	for (int t : _line[_f])
	{

		if (t == _parent) continue;
		DFS(t, _f, _size, _line);
		
		_size[_f] += _size[t];
	}
}


#endif

int solution(int _n, vector<vector<int>> _wires)
{

	int answer = _n;

	vector<vector<int>> line(_n + 1, vector<int>());
	SetLine(_wires, line);

#if first

	vector<bool> visit(_n + 1);

	// 각 간선 끊으면서 최소 경우의 수를 찾는다
	for (const vector<int>& dis : _wires)
	{

		fill(visit.begin(), visit.end(), false);
		visit[1] = true;

		int group1 = DFS(1, visit, line, dis[0], dis[1]);
		int group2 = _n - group1;

		int chk = ABS(group1 - group2);

		if (chk < answer) answer = chk;
	}
#else

	vector<int> size(_n + 1, 0);

	DFS(1, 0, size, line);

	for (int i = 2; i <= _n; i++)
	{

		int group1 = size[i];
		int group2 = _n - size[i];

		int chk = ABS(group1 - group2);
		if (chk < answer) answer = chk;
	}

#endif
	return answer;
}