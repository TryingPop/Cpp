/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 최소공배수
	문제번호 : 13241번

	수학, 정수론, 유클리드 호제법 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define ll long long

using namespace std;

inline ll GetGCD(ll _a, ll _b)
{

	while (_b)
	{

		ll temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

inline ll GetLCM(ll _a, ll _b)
{

	return (_a / GetGCD(_a, _b)) * _b;
}

int main(void)
{

	ll a, b;
	FAST_IO;

	cin >> a >> b;
	cout << GetLCM(a, b);

	return 0;
}