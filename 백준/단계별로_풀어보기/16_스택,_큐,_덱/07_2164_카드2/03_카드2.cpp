/*
날짜 : 2024. 9. 1
이름 : 배성훈
내용 : 카드2
	문제번호 : 2164번

	자료구조, 큐 문제다
*/

#include <iostream>
#include <queue>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;



int main(void)
{

	int n;
	queue<int> q;

	FAST_IO;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		q.push(i);
	}

	while (q.size() > 1)
	{

		q.pop();
		int f = q.front();
		q.pop();
		q.push(f);
	}

	cout << q.front();
	return 0;
}