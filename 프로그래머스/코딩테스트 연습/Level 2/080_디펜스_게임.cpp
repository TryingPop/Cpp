/*
날짜 : 2024. 8. 24
이름 : 배성훈
내용 : 디펜스 게임
	디펜스 게임은 보유한 병사 n명으로 
	연속되는 적의 공격을 순서대로 막는 게임이다

	디펜스 게임은 다음과 같은 규칙으로 진행된다
	처음에 병사 n명을 갖고 있다

	매 라운드마다 enemy[i]마리의 적이 등장한다

	남은 병사 중 enemy[i]명 만큼 소모하여 
	enemy[i] 마리의 적을 막을 수 있다

	게임에는 무적권이라는 스킬이 있으며,
	무적권을 사용하면 병사의 소모없이 
	한 라운드의 공격을 막을 수 있다

	무적권은 최대 k번 사용할 수 있다

	무적권을 적절한 시기에 사용하여
	최대한 많은 라운드를 진행하고 싶다

	처음 갖고 있는 병사의 수 n,
	사용 가능한 무적권의 횟수 k,
	매 라운드마다 공격해오는 적의 수가
	순서대로 담긴 정수 배열 enemy가 매개변수로 주어진다

	몇 라운드까지 막을 수 잇는지 return 하는
	solution 함수 구현


	parameter
	7, 3, { 4, 2, 4, 5, 3, 3, 1 }


	return
	5


	sol
	1, 3, 4 라운드에 무적권을 사용하고
	2, 5 라운드에 각각 2, 3명 병사를 막아내면
	5라운드까지 공격을 막을 수 있다

	이후 6라운드에서는 남은 병사의 수는 2명이고
	적은 3명이므로 막을 수 없다

	이외의 다른 방법으로는 5라운드보다
	더 많은 라운드를 막는 방법은 없다
*/

#include <queue>
#include <vector>

using namespace std;

int solution(int _n, int _k, vector<int> _enemy)
{

	/*
	
	Greedy, PriorityQueue 문제
	*/

	int answer = 0;
	priority_queue<int> pq;

	for (int num : _enemy)
	{

		_n -= num;
		pq.push(num);

		while (_k && _n < 0 && pq.size())
		{

			_k--;
			_n += pq.top();
			pq.pop();
		}

		if (_n < 0) break;

		answer++;
	}

	return answer;
}