/*
날짜 : 2024. 8. 12
이름 : 배성훈
내용 : 진법 변환 2
	문제번호 : 11005번

	수학, 구현 문제다
*/

#include <iostream>

#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

inline char NumToEle(int _num)
{

	if (_num < 10) return _num + '0';
	else return 'A' + _num - 10;
}

inline void Reverse(string& _str)
{

	int t = _str.length() - 1;

	for (int f = 0; f < t; f++, t--)
	{

		char temp = _str[f];
		_str[f] = _str[t];
		_str[t] = temp;
	}
}

int main(void)
{

	int n, k;
	string ret = "";

	FAST_IO;

	cin >> n >> k;

	while (n)
	{

		ret.push_back(NumToEle(n % k));
		n /= k;
	}
	
	Reverse(ret);

	cout << ret;
	return 0;
}