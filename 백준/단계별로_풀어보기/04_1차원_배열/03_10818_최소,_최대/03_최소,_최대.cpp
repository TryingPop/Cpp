/*
날짜 : 2024. 8. 4
이름 : 배성훈
내용 : 최소, 최대
	문제번호 : 10818번

	수학, 구현 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, min = 1e8, max = -1e8, num;
	
	FAST_IO;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		if (num < min) min = num;
		if (max < num) max = num;
	}

	cout << min << ' ' << max;
	return 0;
}