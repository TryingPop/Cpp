#include <string>
#include <vector>

/*
날짜 : 2024. 3. 15
이름 : 배성훈
내용 : 중복된 문자 제거
	문자열 my_string이 매개변수로 주어진다
	my_string에서 중복된 문자를 제거하고 하나의
	문자만 남긴 문자열을 return 하도록
	solution 함수 구현

	my_string은 대문자, 소문자, 공백으로 이루어져있다
	그리고 대문자와 소문자를 구분하다
	공백도 하나의 문자로 구분한다
	중복된 문자 중 가장 앞에 있는 문자만 남긴다
*/

using namespace std;

string solution(string _my_string)
{

	string answer = "";
	answer.reserve(_my_string.length());

	// 0 ~ 25 : 소문자 알파벳
	// 26 ~ 51 : 대문자 알파벳
	// 52 : 공백
	vector<bool> use(53, false);

	for (const char c : _my_string)
	{

		int idx;
		if ('a' <= c && c <= 'z') idx = c - 'a';
		else if ('A' <= c && c <= 'Z') idx = c - 'A' + 26;
		// 공백
		else idx = 52;

		if (use[idx]) continue;
		use[idx] = true;
		answer.push_back(c);
	}

	return answer;
}