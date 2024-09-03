/*
날짜 : 2024. 9. 3
이름 : 배성훈
내용 : 이항 계수 1
	문제번호 : 11050번

	수학, 구현, 조합론 문제다
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int Comb(int _n, int _k)
{

	if (dp[_n][_k] != -1) return dp[_n][_k];
	int& ret = dp[_n][_k];
	ret = 0;
	if (_k == 0 || _n == _k) return ret = 1;
	else if (_k == 1) return ret = _n;

	ret = Comb(_n - 1, _k) + Comb(_n - 1, _k - 1);
	return ret;
}

int main(void)
{

	int n, k;
	cin >> n >> k;

	dp.resize(n + 1, vector<int>(n + 1, -1));
	cout << Comb(n, k);

	return 0;
}