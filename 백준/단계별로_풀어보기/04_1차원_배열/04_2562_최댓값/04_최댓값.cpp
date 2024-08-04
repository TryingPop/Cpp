/*
날짜 : 2024. 8. 4
이름 : 배성훈
내용 : 최댓값
	문제번호 : 2562번

	구현 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'
using namespace std;

int main(void)
{

	int num, max = -1, idx = -1;

	FAST_IO;
	for (int i = 1; i <= 9; i++)
	{

		cin >> num;

		if (max < num)
		{

			max = num;
			idx = i;
		}
	}

	cout << max << endl;
	cout << idx;

	return 0;
}