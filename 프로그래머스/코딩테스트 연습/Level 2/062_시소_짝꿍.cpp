/*
날짜 : 2024. 8. 6
이름 : 배성훈
내용 : 시소 짝꿍
	어느 공원 놀이터에는 시소가 하나 설치되어 있다
	이 시소는 중심으로부터 2(m), 3(m), 4(m) 거리의 지점에 좌석이 하나씩 있다

	이 시소를 두 명이 마주보고 탄다고 할 때,
	시소가 평형인 상태에서 각각에 의해 시소에 걸리는 토크의 크기가 
	서로 상쇄되어 완전한 균형을 이룰 수 있다면
	그 두사람을 시소 짝꿍이라 한다

	즉, 탑승한 사람의 무게와 시소 축과 좌석 간의 거리의 곱이 양쪽 다 같다면
	시소 짝꿍이라고 할 수 있다

	사람들의 몸무게 목록 weights가 주어질 때,
	시소 짝꿍이 몇 쌍 존재하는지 구하여
	return 하도록 solution 함수 구현

	weights의 길이는 10만 이하 2 이상인 자연수
	weights의 원소는 1000 이하 100 이상의 자연수


	parameter
	{ 100, 180, 360, 100, 270 }


	return
	4


	sol
	100 - 100	( 2m, 2m )
	180 - 270	( 3m, 2m )
	180 - 360	( 4m, 2m )
	270 - 360	( 4m, 3m )

	이렇게 짝꿍이 존재한다
*/

#include <vector>

#define ll long long

using namespace std;

inline void CntVec(const vector<int>& _vec, vector<int>& _ret)
{

	/*
	
	vec 원소 값들의 개수를 세어
	ret에 저장
	*/
	for (int num : _vec)
	{

		_ret[num]++;
	}
}

ll solution(vector<int> _weights)
{

	/*
	
	브루트 포스, 그리디
	몸무게 범위가 작다
	자신보다 가벼운 사람들과 비교해 시소 짝꿍을 찾는다
	중복으로 세어서 안되고, 자기보다 큰 사람이랑 매칭되어야 할 경우는
	자기보다 큰 사람에서 카운팅된다
	*/
	ll answer = 0LL;

	vector<int> cnt(1'001, 0);
	CntVec(_weights, cnt);

	for (int i = 100; i <= 1'000; i++)
	{

		if (cnt[i] == 0) continue;

		// 같은 거리에 타는 경우
		answer += (1LL * cnt[i]) * (cnt[i] - 1) / 2;

		// 상대가 4m에 내가 2m에 타는 경우
		if (i % 2 == 0 && cnt[i / 2]) answer += 1LL * cnt[i] * cnt[i / 2];
		// 상대가 4m에 내가 3m에 타는 경우
		if ((i * 3) % 4 == 0 && cnt[(i * 3) / 4]) answer += 1LL * cnt[i] * cnt[(i * 3) / 4];
		// 상대가 3m에 내가 2m에 타는 경우
		if (i % 3 == 0 && cnt[2 * i / 3]) answer += 1LL * cnt[i] * cnt[2 * i / 3];
	}

	return answer;
}