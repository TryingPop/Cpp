/*
날짜 : 2024. 9. 13
이름 : 배성훈
내용 : 유사 칸토어 비트열
	수학에서 칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로
	[0, 1] 부터 시작하여 각 구간을 3등분하여
	가운데 구간을 반복적으로 제외하는 방식으로 만들어진다

	남아는 칸토어 집합을 조금 변형하여 유사 칸토어 비트열을 만들었다
	유사 칸토어 비트열은 다음과 같이 정의된다
	0번째 유사 칸토어 비트열은 "1"이다

	n번째 유사 칸토어 비트열은 n - 1 번째 유사 칸토어 비트열에서의 1을
	11011로 치환하고 0을 00000로 치환하여 만든다

	남아는 n번째 유사 칸토어 비트열에서 특정 구간 내의 1의 개수가 몇 개인지
	궁금해졌다

	n과 1의 개수가 몇 개인지 알고 싶은 구간을 나타내는 l, r이 주어졌을 때,
	그 구간 내의 1의 개수를 return 하는 solution 함수 구현

	n은 20이하인 자연수,
	l, r은 5^n이하인 자연수

	l <= r < l + 10'000'000

	l과 r은 비트열에서의 인덱스이며  폐구간 [l, r]을 의미한다


	parameter
	2, 4, 17


	return
	8


	sol
	2번째 유사 칸토어 비트열은
	110 "11110110000011" 0111011
	여기서 4 ~ 17번째 구간은 "11110110000011"이고
	1이 8개 이다
*/

#define ll long long

using namespace std;

inline ll GetPow(ll _a, int _exp)
{

	/*
	
	거듭제곱 함수
	*/

	ll ret = 1LL;
	while (_exp)
	{

		if (_exp & 1) ret *= _a;
		_exp >>= 1;
		_a *= _a;
	}

	return ret;
}

int DNC(ll _s, ll _e, ll _l, ll _r)
{

	/*
	
	분할 정복
	*/
	if (_e < _l || _r < _s) return 0;
	else if (_e == _s) return 1;

	ll interval = (_e - _s + 1) / 5;
	int ret = 0;
	for (int i = 0; i < 5; i++)
	{

		if (i == 2) continue;
		ret += DNC(_s + i * interval, _s + (i + 1) * interval - 1, _l, _r);
	}

	return ret;
}

int solution(int _n, ll _l, ll _r)
{

	/*
	
	분할 정복
	20 x 10'000'000
	*/
	ll len = GetPow(5, _n);
	int answer = DNC(0, len - 1, _l - 1, _r - 1);

	return answer;
}