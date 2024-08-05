/*
날짜 : 2024. 8. 5
이름 : 배성훈
내용 : 공 바꾸기
	문제번호 : 10813번

	구현, 시뮬레이션 문제다
*/

#include <iostream>
#include <utility>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '

using namespace std;

int arr[101];

int main(void)
{

	int n, m, f, t;
	FAST_IO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{

		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{

		cin >> f >> t;
		swap(arr[f], arr[t]);
	}

	for (int i = 1; i <= n; i++)
	{

		cout << arr[i] << EMPTY;
	}

	return 0;
}