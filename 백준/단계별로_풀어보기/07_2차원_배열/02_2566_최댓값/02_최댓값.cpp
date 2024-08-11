/*
날짜 : 2024. 8. 11
이름 : 배성훈
내용 : 최댓값
	문제번호 : 2566번

	구현 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'
using namespace std;

int main(void)
{

	int max = -1, row = -1, col = -1, temp;

	FAST_IO;

	for (int r = 1; r <= 9; r++)
	{

		for (int c = 1; c <= 9; c++)
		{

			cin >> temp;
			if (max < temp) 
			{

				max = temp;
				row = r;
				col = c;
			}
		}
	}

	cout << max << endl << row << ' ' << col;
	return 0;
}