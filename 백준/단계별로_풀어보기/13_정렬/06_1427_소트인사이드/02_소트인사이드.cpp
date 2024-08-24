/*
날짜 : 2024. 8. 24
이름 : 배성훈
내용 : 소트인사이드
	문제번호 : 1427번

	문자열, 정렬 문제다
*/

#include <iostream>
#include <vector>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	vector<int> cnt(10, 0);
	string nums;

	FAST_IO;

	cin >> nums;

	for (char c : nums)
	{

		cnt[c - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{

		if (!cnt[i]) continue;
		for (int j = 0; j < cnt[i]; j++)
		{

			cout << i;
		}
	}

	return 0;
}