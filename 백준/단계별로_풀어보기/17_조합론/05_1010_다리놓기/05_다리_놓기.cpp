/*
날짜 : 2024. 9. 3
이름 : 배성훈
내용 : 다리 놓기
	문제번호 : 1010번

	수학, dp, 조합론 문제다
*/

#include <iostream>

#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

vector<vector<int>> dp;

inline int Comb(int _n, int _k)
{

	if (dp[_n][_k] != -1) return dp[_n][_k];
	int& ret = dp[_n][_k];

	if (_n == _k || _k == 0) return ret = 1;
	else if (_k == 1) return ret = _n;

	ret = Comb(_n - 1, _k - 1) + Comb(_n - 1, _k);
	return ret;
}

int main(void)
{

	int t, n, k;
	
	FAST_IO;
	dp.resize(31, vector<int>(31, -1));

	cin >> t;
	while (t--)
	{

		cin >> k >> n;
		cout << Comb(n, k) << endl;
	}

	return 0;
}