/*
날짜 : 2024. 8. 4
이름 : 배성훈
내용 : 공 넣기
	문제번호 : 10810번

	구현, 시뮬레이션 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '
using namespace std;
int arr[101];

int main(void)
{

	int n, m, f, t, num;

	FAST_IO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{

		cin >> f >> t >> num;

		for (int j = f; j <= t; j++)
		{

			arr[j] = num;
		}
	}

	for (int i = 1; i <= n; i++)
	{

		cout << arr[i] << EMPTY;
	}

	return 0;
}