/*
날짜 : 2024. 8. 29
이름 : 배성훈
내용 : 점 찍기
	좌표평면을 좋아하는 진수는 x축과 y축이 직교하는
	2차원 좌표평면에 점을 찍으면서 놀고 있다

	진수는 두 양의 정수 k, d가 주어질 때, 
	다음과 같이 점을 찍는다

	원점 (0, 0)으로부터 
	x축 방향으로 a * k (a = 0, 1, ...), 
	y축 방향으로 b * k (b = 0, 1, ...)
	만큼 떨어진 위치에 점을 찍는다

	원점과 거리가 d를 넘는 위치에는 점을 찍지 않는다

	정수 k와 원점과의 거리를 나타내는 정수 d가 주어질 때,
	점이 총 몇 개 찍히는지 return 하는 solution 함수 구현

	d, k 는 100만 이하의 자연수
	

	parameter
	2, 4


	return
	6


	sol
	(0, 0), (2, 0), (4, 0), (2, 2), (2, 4), (4, 0)
	총 6개 있다
*/

#define ll long long

inline ll BinarySearch(ll _chk)
{

	/*
	
	이분 탐색
	n * n <= chk인
	가장 큰 음이 아닌 정수 n을 찾아 반환
	만약 존재하지 않으면 -1을 반환
	*/
	if (_chk < 0) return -1;
	ll l = 0;
	ll r = 1'000'000;

	while (l <= r)
	{

		ll mid = (l + r) >> 1;

		if (mid * mid <= _chk) l = mid + 1;
		else r = mid - 1;
	}

	return l - 1;
}

ll solution(int _k, int _d)
{

	/*
	
	브루트포스, 수학 문제
	피타고라스 정리를 풀면
	a^2 + b^2 <= d^2 / k^2
	좌변의 a, b가 정수이고 부등화 관계로
	우변의 d^2 / k^2의 소수 부분은 중요하지 않다

	그리고 b = 0일 때 먼저 a^2 <= d^2 / k^2인 a의 최대값 m을 찾는다
	그리고 a = 0, 1, 2, ... , m에 대해
	b^2 <= (d^2 / k^2) - a^2인 
	b의 최대값들을 찾고 b 이하인 음이아닌 정수들의 개수를 세어 누적한다
	*/

	ll chk = (1LL * _d * _d) / (1LL * _k * _k);

	int e = BinarySearch(chk);
	ll answer = e + 1;

	for (ll i = 1; i <= e; i++)
	{

		ll cnt = BinarySearch(chk - (i * i)) + 1;
		answer += cnt;
	}

	return answer;
}