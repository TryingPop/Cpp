/*
날짜 : 2024. 9. 1
이름 : 배성훈
내용 : 도키도키 간식드리미
	문제번호 : 12789번

	자료구조, 스택 문제다
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

	string YES = "Nice";
	string NO = "Sad";

	int n, temp;
	vector<int> stk;

	FAST_IO;

	cin >> n;

	stk.reserve(n);
	int cur = 1;

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		
		stk.push_back(temp);

		while (stk.size() && stk.back() == cur)
		{

			stk.pop_back();
			cur++;
		}
	}

	cout << (stk.empty() ? YES : NO);
	return 0;
}