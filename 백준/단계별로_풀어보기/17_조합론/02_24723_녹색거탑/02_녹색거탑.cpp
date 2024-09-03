/*
날짜 : 2024. 9. 3
이름 : 배성훈
내용 : 녹색거탑
	문제번호 : 24723번

	수학, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

inline int GetPow(int _n, int _exp) 
{

	int ret = 1;
	while (_exp)
	{

		if (_exp & 1) ret *= _n;

		_exp >>= 1;
		_n *= _n;
	}

	return ret;
}

int main(void)
{

	int n;
	cin >> n;

	cout << GetPow(2, n);
	return 0;
}