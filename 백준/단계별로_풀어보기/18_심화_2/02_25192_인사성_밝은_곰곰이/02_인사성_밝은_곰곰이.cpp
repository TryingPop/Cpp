/*
날짜 : 2024. 9. 4
이름 : 배성훈
내용 : 인사성 밝은 곰곰이
	문제번호 : 25192번

	자료 구조, 해시 문제다
*/

#include <iostream>
#include <unordered_map>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, ret = 0, ent = 0;
	string ENTER = "ENTER", temp;
	unordered_map<string, int> id;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		if (temp == ENTER)
		{

			ent++;
			continue;
		}

		if (id[temp] == ent) continue;
		id[temp] = ent;
		ret++;
	}

	cout << ret;
	return 0;
}