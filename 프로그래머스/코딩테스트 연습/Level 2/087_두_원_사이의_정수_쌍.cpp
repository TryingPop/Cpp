/*
날짜 : 2024. 8. 31
이름 : 배성훈
내용 : 두 원 사이의 정수 쌍
	x축과 y축으로 이루어진 2차원 직교 좌표계에
	중심이 원점인 서로 다른 크기의 원이 두개 주어진다
	반지름을 나타내는 두 정수 r1, r2가 매개변수로 주어질 때,
	두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를
	return 하는 solution 함수 구현

	각 원 위의 점도 포함하여 센다

	r1, r2는 100만 이하의 자연수이고
	r1 < r2이다

	parameter
	2, 3


	return
	20


	sol
	y축과 1사분면쪽을 포함한 곳에 있는 점은
	(0, 1), (0, 2),
	(1, 2),
	(2, 1), (2, 2)
	로 총 5개이다

	이를 2사분면과 x축,
	3사분면과 y축, 4사분면과 x축의 개수도
	동일하므로 총 20개이다
*/

#include <cmath>

#define ll long long
#define E 1e-9

using namespace std;

inline ll MySqrt(ll _r, ll _i)
{

	/*
	
	E는 부동소수점 오차
	*/
	if (_r <= _i) return 0;
	return sqrt((_r * _r) - (_i * _i)) + E
}

inline bool Add(ll _chk, ll _r, ll _i)
{

	/*
	
	끝 점에 걸치는지 확인
	*/
	return (_chk * _chk) == (_r * _r) - (_i * _i);
}

ll solution(int _r1, int _r2)
{

	/*
	
	수학
	*/

	ll answer = 0;
	for (int i = 0; i < _r2; i++)
	{

		answer += MySqrt(_r2, i);
		ll chk = MySqrt(_r1, i);

		answer -= chk;
		if (Add(chk, _r1, i)) answer++;
	}

	answer--;
	answer *= 4;
	return answer;
}