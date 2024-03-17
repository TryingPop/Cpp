#include <string>
#include <vector>

/*
날짜 : 2024. 3. 17
이름 : 배성훈
내용 : 한 번만 등장한 문자
	문자열 s가 매개변수로 주어질 때,
	s에서 한 번만 등장하는 문자를
	사전 순으로 정렬한 문자열을
	return 하는 solution 함수 구현

	한 번만 등장하는 문자가 없을 경우
	빈 문자열을 return

	s는 소문자로만 이루어져 있다
*/

using namespace std;

string solution(string _s)
{

	string answer = "";
	answer.reserve(_s.length());

	vector<int> cnt(26, 0);

	for (const char c : _s)
	{

		// 문자 개수 세기
		cnt[c - 'a']++;
	}

	for (int i = 0; i < cnt.size(); i++)
	{

		// 한 개만 문자를 이어 붙인다
		if (cnt[i] == 1) answer.push_back(i + 'a');
	}

	return answer;
}