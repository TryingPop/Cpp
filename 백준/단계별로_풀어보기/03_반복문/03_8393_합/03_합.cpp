/*
날짜 : 2024. 8. 1
이름 : 배성훈
내용 : 합
	문제번호 : 8393번

	수학, 구현 문제다
*/

#include <iostream>

#define fastio cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n;

	fastio;
	cin >> n;

	cout << (n * n + n) / 2;

	return 0;
}