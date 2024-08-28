/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 가로수
	문제번호 : 2485번

	수학, 정수론, 유클리드 호제법 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

inline int GetGCD(int _a, int _b)
{

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int main(void)
{

	int n, s, temp, gcd, len;
	FAST_IO;

	cin >> n >> s >> temp;
	gcd = temp - s;
	for (int i = 2; i < n; i++)
	{

		cin >> temp;
		gcd = GetGCD(gcd, temp - s);
	}

	len = (temp - s) / gcd;
	cout << len - n + 1;
	
	return 0;
}