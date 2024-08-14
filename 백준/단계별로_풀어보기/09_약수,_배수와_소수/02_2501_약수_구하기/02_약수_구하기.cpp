/*
날짜 : 2024. 8. 14
이름 : 배성훈
내용 : 약수 구하기
	문제번호 : 2501번

	수학, 브루트포스 문제다
*/

#include <iostream>

using namespace std;

inline int GetRet(int _n, int _k) 
{

	for (int i = 1; i <= _n; i++)
	{

		if (_n % i) continue;
		_k--;

		if (_k) continue;

		return i;
	}

	return 0;
}

int main(void)
{

	int n, k;
	cin >> n >> k;

	cout << GetRet(n, k);
	return 0;
}