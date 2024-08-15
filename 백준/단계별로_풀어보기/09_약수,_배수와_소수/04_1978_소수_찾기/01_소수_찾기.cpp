/*
날짜 : 2024. 8. 15
이름 : 배성훈
내용 : 소수 찾기
	문제번호 : 1978번

	수학, 정수론, 소수 판정 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define MAX 1'000
using namespace std;

inline void SetNotPrimeArr(vector<bool>& _notPrime)
{

	_notPrime.resize(MAX + 1, false);
	_notPrime[0] = true;
	_notPrime[1] = true;

	for (int i = 2; i <= MAX; i++)
	{

		if (_notPrime[i]) continue;

		for (int j = i << 1; j <= MAX; j += i) 
		{

			_notPrime[j] = true;
		}
	}
}

int main(void)
{

	int n, chk, ret = 0;
	vector<bool> notPrime;

	FAST_IO;
	SetNotPrimeArr(notPrime);

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> chk;
		if (notPrime[chk]) continue;
		ret++;
	}

	cout << ret;
	return 0;
}