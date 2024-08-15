/*
날짜 : 2024. 8. 15
이름 : 배성훈
내용 : 소수
	문제번호 : 2581번

	수학, 정수론, 소수 판정 문제다
*/

#include <iostream>
#include <vector>

#define MAX 10'000
#define endl	'\n'
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

	int s, e, ret1 = 0, ret2 = 0;
	vector<bool> notPrime;

	cin >> s >> e;
	SetNotPrimeArr(notPrime);

	for (int i = s; i <= e; i++)
	{

		if (notPrime[i]) continue;

		ret1 += i;
		if (ret2 == 0) ret2 = i;
	}

	if (ret1) cout << ret1 << endl << ret2;
	else cout << -1;
	return 0;
}