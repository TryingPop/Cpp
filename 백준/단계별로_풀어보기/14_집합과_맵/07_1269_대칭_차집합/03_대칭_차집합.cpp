/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 대칭 차집합
	문제번호 : 1269번

	자료구조, 해시 문제다
*/

#include <iostream>
#include <unordered_set>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int a, b, temp, ret;
	unordered_set<int> chk;
	FAST_IO;

	cin >> a >> b;
	ret = a + b;
	for (int i = 0; i < a; i++)
	{

		cin >> temp;
		chk.insert(temp);
	}

	for (int i = 0; i < b; i++)
	{

		cin >> temp;
		if (chk.count(temp)) ret -= 2;
	}

	cout << ret;
	return 0;
}