/*
날짜 : 2024. 8. 3
이름 : 배성훈
내용 : 별 찍기 - 1
	문제번호 : 2438번
*/

#include <iostream>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n;
	fastio;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j <= i; j++)
		{

			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}