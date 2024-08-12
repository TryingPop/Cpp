/*
날짜 : 2024. 8. 12
이름 : 배성훈
내용 : 중앙 이동 알고리즘
	문제번호 : 2903번

	수학 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, x;
	FAST_IO;

	cin >> n;
	x = 1 << n;
	x++;

	cout << x * x;
	return 0;
}