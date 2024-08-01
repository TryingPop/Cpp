/*
날짜 : 2024. 8. 1
이름 : 배성훈
내용 : 두 큐 합 같게 만들기
	길이가 같은 두 개의 큐가 주어진다
	하나의 큐를 골라 원소를 추출하고,
	추출(pop)된 원소를 다른 큐에 집어넣는(insert) 작업을 통해
	각 큐의 원소 합이 같도록 만들려고 한다

	이때 필요한 작업의 최소 횟수를 찾으려고 한다
	1번의 pop과 1번의 insert를 합쳐서 작업을 1회 수행한 것으로 간주한다

	큐를 배열로 표현하며,
	배열 앞쪽에 있을수록 먼저 집어넣은 원소임을 의미한다

	길이가 같은 두 개의 큐를 나타내는 정수 배열
	queue1, queue2가 매개변수로 주어질 때,
	각 큐의 원소 합을 같게 만들기 위해 필요한 작업의 최소횟수를
	return 하는 solution 함수를 구현
	만약 같게 만들 수 없다면 -1을 출력

	queue1, queue2의 길이는 30만 이하의 자연수
	queue1, queue2 원소의 크기는 10억 이하의 자연수


	parameter
	{ 3, 2, 7, 2 }, { 4, 6, 5, 1 }


	return
	2


	sol
	{ 2, 7, 2, 4 }, { 6, 5, 1, 3 }으로 만들면 된다
*/

#include <vector>

#define ll long long

using namespace std;

inline ll GetSum(vector<int>& _arr)
{

	/*
	
	배열의 총합 찾아준다
	*/
	ll ret = 0LL;
	for (int num : _arr)
	{

		ret += num;
	}

	return ret;
}

inline int GetRet(int _l, int _r, int _size)
{

	/*
	
	l, r을 기준으로 
	큐에서 최소 몇 번 꺼내야하는지 찾아준다
	*/
	if (_r < _size - 1) return _r - _l + 1 + _size;
	else return _r - _size + 1 + _l;
}

int solution(vector<int> _queue1, vector<int> _queue2)
{

	/*
	
	두 포인터
	*/

	// 큐 이어붙이기
	_queue1.insert(_queue1.end(), _queue2.begin(), _queue2.end());

	// 새로운 이름
	vector<int>& link = _queue1;

	ll find = GetSum(link);

	// 홀수면 같게 못만든다
	if (find % 2) return -1;

	// 두 포인터
	find /= 2;			// 찾을 값

	int l = 0;			// 왼쪽
	int r = 0;			// 오른쪽
	int answer = -1;	// 최소 시행횟수
	ll cur = link[0];	// 현재 누적합
	int size = _queue2.size();
	
	while (l < link.size() && r < link.size())
	{

		// 같은 경우
		if (cur == find)
		{

			// 시행횟수 최소 값 인지 판별
			int cnt = GetRet(l, r, size);
			if (answer == -1 || cnt < answer) answer = cnt;
		}

		// 이후 범위 조절
		if (cur < find) cur += link[++r];
		else cur -= link[l++];
	}

	return answer;
}