/*
날짜 : 2024. 8. 30
이름 : 배성훈
내용 : 균형잡힌 세상
	문제번호 : 4949번

	자료구조, 문자열, 스택 문제다
*/

#include <string>
#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int arr[100];
int len;

inline bool Chk(string& _str) 
{

	len = 0;
	for (const char c : _str)
	{

		if (c == '(' || c == '[') arr[len++] = c;
		else if (c == ')')
		{

			if (len && arr[len - 1] == '(') len--;
			else return false;
		}
		else if (c == ']')
		{

			if (len && arr[len - 1] == '[') len--;
			else return false;
		}
	}

	return len == 0;
}

int main(void)
{

	const string YES = "yes\n";
	const string NO = "no\n";

	string temp;
	int n;

	FAST_IO;

	while (true)
	{

		getline(cin, temp);
		if (temp == ".") break;
		cout << (Chk(temp) ? YES : NO);
	}

	return 0;
}