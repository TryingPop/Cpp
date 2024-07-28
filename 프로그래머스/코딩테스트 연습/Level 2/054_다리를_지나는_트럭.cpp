/*
날짜 : 2024. 7. 29
이름 : 배성훈
내용 : 다리를 지나는 트럭
	트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순서로 건너려 한다
	모든 트럭이 다리를 건너러면 최소 몇 초가 걸리는지 확인해야 한다

	다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며,
	다리는 weigth 이하까지의 무게를 견딜 수 있다
	단, 다리에 완전히 오르지 않은 트럭의 무게는 무시한다

	다리에 올라갈 수 있는 트럭 수 bridge_length,
	다리가 견딜 수 있는 무게 weight,
	트럭별 무게 truck_weights가 매개변수로 주어질 때,
	모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지
	return 하는 solution 함수 구현

	weight, bridge_length는 1만 이하의 자연수
	truck_weights의 길이는 1만 이하이고
	모든 트럭의 무게는 weight 이하이다


	parameter
	2, 10, { 7, 4, 5, 6 }


	return
	8


	sol
	
	시간	지나간 트럭		다리 위에 트럭		대기중인 트럭
	0											7, 4, 5, 6
	1						7					4, 5, 6
	2						7					4, 5, 6
	3		7				4					5, 6
	4		7				4, 5				6
	5		7, 4			5					6
	6		7, 4, 5			6					
	7		7, 4, 5			6
	8		7, 4, 5, 6

	이된다
*/

#include <vector>
#include <queue>
#include <cmath>

#define mp make_pair
#define pii pair<int, int>

using namespace std;

int solution(int _bridge_length, int _weight, vector<int> _truck_weights)
{

	/*
	
	큐 문제
	*/
	int answer = 0;

	queue<pii> q;			// 차량 무게, 다리 진입 시간
	
	int curTime = 0;
	int curWeight = 0;

	for (int truck : _truck_weights)
	{

		// 다리 무게 확인
		while (q.size() && _weight < curWeight + truck)
		{

			// 무게 초과
			// 맨앞의 트럭
			pii f = q.front();
			q.pop();
			// 다리에 있는 마지막 시간으로
			curTime = max(curTime, f.second + _bridge_length - 1);
			curWeight -= f.first;
		}

		// 차량올라간다
		curTime++;
		curWeight += truck;
		q.push(mp(truck, curTime));
	}

	answer = q.back().second + _bridge_length;
	return answer;
}