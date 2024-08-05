/*
날짜 : 2024. 8. 5
이름 : 배성훈
내용 : 과제 안 내신 분..?
	문제번호 : 5597번

	구현 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

bool arr[31];

int main(void)
{

	int n;

	FAST_IO;

	for (int i = 0; i < 28; i++)
	{

		cin >> n;
		arr[n] = true;
	}

	for (int i = 1; i <= 30; i++)
	{

		if (arr[i]) continue;
		cout << i << endl;
	}

	return 0;
}