/*
날짜 : 2024. 8. 3
이름 : 배성훈
내용 : 별 찍기 - 2
	문제번호 : 2439번

	구현 문제다
*/

#include <iostream>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define STAR '*'
#define EMPTY ' '
#define endl '\n'

using namespace std;

int main(void)
{

	int n;
	fastio;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{

		for (int j = n - i; j > 0; j--)
		{

			cout << EMPTY;
		}

		for (int j = 0; j < i; j++)
		{

			cout << STAR;
		}

		cout << endl;
	}
}