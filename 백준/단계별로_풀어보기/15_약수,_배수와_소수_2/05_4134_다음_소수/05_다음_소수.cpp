/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 다음 소수
	문제번호 : 4134번

	수학, 브루트 포스, 정수론, 소수판정 문제다
*/


#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define ull unsigned long long
#define endl	'\n'

using namespace std;

ull GetPow(ull _a, ull _exp, ull _mod)
{

	ull ret = 1;

	while (_exp)
	{

		if (_exp & 1ULL) ret = (ret * _a) % _mod;

		_a = (_a * _a) % _mod;
		_exp >>= 1;
	}

	return ret;
}

bool ChkNotPrime(ull _a, ull _n)
{

	if (_n == 2 || _n == _a) return false;
	else if (_n < 2) return true;

	ull d = _n - 1;
	while (true)
	{

		ull temp = GetPow(_a, d, _n);

		if (temp == _n - 1) return false;
		else if (temp != 1) return true;

		if (d & 1ULL) return temp != 1 && temp != _n - 1;
		d >>= 1;
	}
}

bool Miller_Rabin(ull _n)
{

	int chk[] = { 2, 7, 61 };

	for (int i = 0; i < 3; i++)
	{

		if (ChkNotPrime(chk[i], _n)) return false;
	}

	return true;
}

int main(void)
{

	int n;
	ull a;

	FAST_IO;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a;
		while (true)
		{

			if (Miller_Rabin(a)) break;
			a++;
		}

		cout << a << endl;
	}
	return 0;
}