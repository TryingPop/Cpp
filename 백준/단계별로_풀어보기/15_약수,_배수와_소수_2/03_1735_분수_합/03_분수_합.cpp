/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 분수 합
	문제번호 : 1735번

	수학, 정수론, 유클리드 호제법 문제다
*/

#include <iostream>

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

	int a, b, c, d, up, down, gcd;
	cin >> a >> b >> c >> d;

	up = a * d + b * c;
	down = b * d;

	gcd = GetGCD(up, down);
	cout << up / gcd << ' ' << down / gcd;

	return 0;
}