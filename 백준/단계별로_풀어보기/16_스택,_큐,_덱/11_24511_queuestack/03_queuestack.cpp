/*
날짜 : 2024. 9. 2
이름 : 배성훈
내용 : queuestack
	문제번호 : 24511번

	자료 구조, 스택, 덱, 큐 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
using namespace std;

int deck[200'000];
int h = 100'000, t = 100'000 - 1;

int main(void)
{

	int n, temp, m;
	vector<bool> isS;

	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		isS.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		if (isS[i]) continue;
		deck[++t] = temp;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{

		cin >> temp;
		deck[--h] = temp;
		cout << deck[t--] << EMPTY;
	}

	return 0;
}