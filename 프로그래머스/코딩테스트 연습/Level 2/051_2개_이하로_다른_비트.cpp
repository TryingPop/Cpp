/*
날짜 : 2024. 7. 26
이름 : 배성훈
내용 : 2개 이하로 다른 비트
	양의 정수 x에 대한 함수 F(x)를 다음과 같이 정의한다
	x보다 크고 x와 비트가 1 ~ 2개 다른 수들 중에 제일 작은 수

	정수들이 담긴 배열 numbers가 매개변수로 주어질 때,
	numbers의 모든 수들에 대하여 각 수 F의 값을 배열에 차례대로 담아
	return 하는 solution 함수 구현

	numbers의 길이는 10만 이하의 자연수이고,
	numbers의 모든 원소는 10^15보다 작은 음이아닌 정수이다

	parameter
	{ 2, 7 }


	return
	{ 3, 11 }


	sol
	2는 0000'0010이다
	2보다 3은 2보다 큰 수 중에 가장 작은 수이며
	0000'0011이므로
	2와 비트가 1개 다르다

	7은 0000'0111이다
	7과 비트가 1개 다른 것 중 7보다 크면서 가장 작은건
	0000'1111, 15이다
	7과 비트가 2개 다른것은 
	0000'1011, 11이다
*/

#include <vector>

#define ll long long

using namespace std;

inline ll F(ll _num)
{

	/*
	
	맨 오른쪽의 0을 찾아 1로 바꾼다
	그러면 x보다 큰 수가 보장된다

	바꾼 0을 기준으로 오른쪽에 1이 존재하면
	바꾼 0과 가장 가까운 1을 0으로 바꾼게 가장 작은 수가 된다
	*/
	int b = -1;

	// 2^50 > 10^15
	for (int i = 0; i <= 50; i++)
	{

		if (_num & (1LL << i)) b = i;
		else 
		{

			_num |= 1LL << i;
			if (b != -1) _num ^= 1LL << b;

			return _num;
		}
	}

	return -1;
}

vector<ll> solution(vector<ll> _numbers)
{

	vector<ll> answer;
	answer.reserve(_numbers.size());

	for (const ll num : _numbers)
	{

		ll ret = F(num);
		answer.push_back(ret);
	}

	return answer;
}