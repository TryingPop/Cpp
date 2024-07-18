/*
날짜 : 2024. 7. 18
이름 : 배성훈
내용 : 더 맵게
	모든 음식의 스코빌 지수를 K 이상으로 만들려고 한다
	모든 음식의 스코빌 지수를 K 이상으로 만들기 위해
	스코빌 지수가 가장 낮은 두 개의 음식을 특별한 방법으로 섞어 새로운 음식을 만든다
	섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수
	+ 2 x 두 번째로 맵지 않은 음식의 스코빌 지수

	모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞는다

	스코빌 지수를 담은 배열 scoville와 원하는 스코빌 지수 k가 주어질 때,
	모든 음식의 스코빌 지수를 k 이상으로 만들기 위해 섞어야 하는 최소 회수를
	return 하는 solution 함수 구현

	scoville의 길이는 2 이상 100만 이하이다

	k는 0 이상 10억 이하

	scoville의 원소는 각각 0이상 100만 이하다

	모든 음식의 스코빌 지수를 k이상으로 만들 수 없는 경우에는 -1을 반환


	parameter
	{ 1, 2, 3, 9, 10, 12 }, 7


	return
	2


	sol
	1과 2를 섞어 새로운 음식을 만든다
	그러면 새로운 음식의 스코빌 지수는 5이다
	{ 3, 5, 9, 10, 12 }

	그리고 3과 5를 섞어 새로운 음식을 만든다
	그러면 새로운 음식의 스코빌 지수는 13이다
	{ 9, 10, 12, 13 }

	모두 7이상이므로 종료한다
	만든 새로운 음식은 총 2개이다
*/

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> _scoville, int _k)
{

	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	int other = 0;		// 마지막에 남은거 합친다

	for (int food : _scoville)
	{

		// K 이하만 넣어서 합친다
		if (food < _k) pq.push(food);
		else other++;
	}

	while (1 < pq.size())
	{

		// 합치기
		answer++;
		int newFood = pq.top();
		pq.pop();
		newFood += 2 * pq.top();
		pq.pop();

		if (newFood < _k) pq.push(newFood);
		// 완제품이면 완제품 추가
		else other++;
	}

	if (pq.size())
	{

		// 완제품과 합치면 된다
		if (other) answer++;
		// 모두 섞어도 k이하인 경우다
		else answer = -1;
	}

	return answer;
}