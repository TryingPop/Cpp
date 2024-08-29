/*
날짜 : 2024. 8. 29
이름 : 배성훈
내용 : 소수 구하기
	문제번호 : 1929번

	수학, 정수론, 소수 판정, 에라토스테네스의 체 문제다
*/

#include <iostream>
#include <vector>

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

	vector<bool> prime;
	int s, e;

	cin >> s >> e;

	Eratosthenes(prime);

	for (int i = s; i <= e; i++)
	{

		if (prime[i]) cout << i << endl;
	}

	return 0;
}