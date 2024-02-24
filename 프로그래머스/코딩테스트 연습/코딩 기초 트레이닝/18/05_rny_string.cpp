#include <string>
#include <vector>

/*
날짜 : 2024. 2. 24
이름 : 배성훈
내용 : rny_string
	m과 rn이 모양이 비슷하게 생긴 점을 활용해
	문자열에 장난을 친다

	문자열 rny_string이 주어질 때,
	rny_string의 모든 m을 rn으로 바꾼 문자열을
	return하는 solution 함수를 작성
*/

using namespace std;

string solution(string _rny_string)
{

	string answer;

	string rn = "rn";
	answer.reserve(_rny_string.length());

	for (const char c : _rny_string)
	{

		if (c == 'm') answer.append(rn);
		else answer.push_back(c);
	}

	return answer;
}