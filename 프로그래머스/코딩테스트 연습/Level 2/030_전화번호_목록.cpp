/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : 전화번호 목록
	전화번호부에 적힌 전화번호 중,
	한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려고 한다

	전화번호부에 적힌 전화번호를 담은 배열
	phone_book이 매개변수로 주어질 때,

	어떤 번호가 다른 번호의 접두어인 경우가 있으면
	false를 그렇지 않으면 true를
	return 하는 solution 함수 구현

	phone_book의 길이는 1 이상 100만 이하,
	각 전화번호의 길이는 1 이상 20 이하

	중복되는 전화번호는 없다


	parameter
	{ "119", "97674223", "1195524421" }


	return
	false


	sol
	119가 1195524421에 접두사로 들어간다
	그래서 false
*/

#if first
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool MyComp(string& _str1, string& _str2)
{

	/*

	문자열 사전식 배열
	*/
	int len = _str2.length() < _str1.length() ? _str2.length() : _str1.length();

	for (int i = 0; i < len; i++)
	{

		if (_str1[i] != _str2[i]) return _str1[i] < _str2[i];
	}

	return _str1.length() < _str2.length();
}

bool solution(vector<string> _phone_book)
{

	bool answer = true;

	/*

	lcp 배열 구할 때 쓰는 아이디어를 가져왔다
	사전식 정렬해 앞뒤만 비교하면 된다
	O(N * M log N), N : phone_book의 길이, M : 각 전화번호의 길이
	*/
	sort(_phone_book.begin(), _phone_book.end(), MyComp);

	// O(N * M), N : phone_book의 길이, M : 각 전화번호의 길이
	for (int i = 1; i < _phone_book.size(); i++)
	{

		if (_phone_book[i].find(_phone_book[i - 1]) != 0) continue;

		answer = false;
		break;
	}

	return answer;
}
#else

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool solution(vector<string> _phone_book)
{

	unordered_set<string> chk;
	chk.reserve(_phone_book.size());
	for (const string& str: _phone_book)
	{

		chk.insert(str);
	}

	string temp;
	for (const string& str : _phone_book)
	{

		temp = str;
		temp.pop_back();
		while (temp.size())
		{

			if (chk.count(temp)) return false;
			temp.pop_back();
		}
	}

	return true;
}
#endif