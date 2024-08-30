/*
날짜 : 2024. 8. 30
이름 : 배성훈
내용 : 제로
	문제번호 : 10773번

	구현, 자료구조, 스택 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define ll long long

using namespace std;

int arr[100'000];
int len;

int main(void)
{

	int n, temp;
	ll ret;
	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		if (temp) arr[len++] = temp;
		else len = len > 0 ? len - 1 : 0;
	}

	ret = 0LL;
	for (int i = 0; i < len; i++)
	{

		ret += arr[i];
	}

	cout << ret;
	return 0;
}