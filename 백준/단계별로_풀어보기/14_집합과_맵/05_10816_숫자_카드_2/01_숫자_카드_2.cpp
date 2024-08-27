/*
날짜 : 2024. 8. 27
이름 : 배성훈
내용 : 숫자 카드 2
	문제번호 : 10816번

	자료구조, 정렬, 이분 탐색, 해시 문제다
*/

#include <iostream>
#include <unordered_map>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '
using namespace std;

int main(void)
{

	int n, temp;
	unordered_map<int, int> my;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		my[temp]++;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		cout << my[temp] << EMPTY;
	}

	return 0;
}