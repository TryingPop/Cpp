/*
날짜 : 2024. 8. 29
이름 : 배성훈
내용 : 골드바흐 파티션
	문제번호 : 17103번

	수학, 정수론, 소수 판정, 에라토스테네스의 체 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

inline void Eratosthenes(vector<bool>& _prime)
{

	_prime.resize(1'000'001, true);
	_prime[0] = false;
	_prime[1] = false;

	for (int i = 2; i <= 1'000'000; i++)
	{

		if (!_prime[i]) continue;

		for (int j = i << 1; j <= 1'000'000; j += i)
		{

			_prime[j] = false;
		}
	}
}

int main(void)
{

	int n, m, cnt, chk;
	vector<bool> prime;
	FAST_IO;

	Eratosthenes(prime);

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> m;
		cnt = 0;
		for (int j = 2; j <= m / 2; j++)
		{

			chk = m - j;
			if (!prime[j] || !prime[chk]) continue;

			cnt++;
		}

		cout << cnt << endl;
	}
}