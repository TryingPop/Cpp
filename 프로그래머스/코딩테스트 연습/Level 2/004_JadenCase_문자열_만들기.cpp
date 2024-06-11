/*
날짜 : 2024. 6. 11
이름 : 배성훈
내용 : JadenCase 문자열 만들기
	JadenCase란 모든 단어의 첫 문자가 대문자이고,
	그 이외의 알파벳은 소문자인 문자열

	단, 첫 문자가 알파벳이 아닐 때에는
	이어지는 알파벳은 소문자로 쓰면 된다

	문자열 s가 주어졌을 때, s를 JadenCase로 바꾼
	문자열을 return 하는 solution 함수 구현

	s는 알파벳과 숫자, 공백 문자로 이뤄졌다
	숫자는 첫 문자로만 나온다
	숫자로만 이루어진 단어는 없다
	공백 문자가 연속해서 나올 수 있다

	3people unFollowed me
	3people Unfollowed Me
	로 바꿔야한다
*/

#include <string>

using namespace std;

string solution(string _s)
{

	string answer;
	answer.reserve(_s.length());

	bool isUp = true;
	for (char c : _s)
	{

		if ('A' <= c && c <= 'Z')
		{

			if (!isUp) c += 'a' - 'A';
			else isUp = false;
		}
		else if ('a' <= c && c <= 'z')
		{

			if (isUp)
			{

				isUp = false;
				c -= 'A' - 'a';
			}
		}
		else if (c == ' ') isUp = true;
		else if (isUp) isUp = false;

		answer.push_back(c);
	}

	return answer;
}