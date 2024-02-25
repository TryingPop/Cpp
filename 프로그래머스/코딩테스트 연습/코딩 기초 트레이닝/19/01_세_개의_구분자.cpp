#include <vector>
#include <string>

/*
날짜 : 2024. 2. 25
이름 : 배성훈
내용 : 세 개의 구분자
	임의의 문자열이 주어질 때,
	문자 a, b, c를 구분자로 사용해
	문자열로 나누고자 한다

	문자열 myStr이 주어졌을 때,
	a, b, c를 사용해 나눠진 문자열을 순서대로
	저장한 배열을 return 하는 solution 함수 구현

	단, 두 구분자 사이에 다른 문자가 없을 경우에
	아무것도 저장하지 않으며
	return 할 배열이 빈 배열이라면
	{ EMPTY }를 return
*/

using namespace std;

vector<string> solution(string _myStr)
{

	vector<string> answer;

	string temp;
	temp.reserve(_myStr.length());

	for (const char c : _myStr)
	{

		if (c == 'a' || c == 'b' || c == 'c')
		{

			if (temp.empty()) continue;

			answer.push_back(temp);
			temp.clear();
		}
		else temp.push_back(c);
	}

	if (!temp.empty()) answer.push_back(temp);

	if (answer.empty()) answer.push_back("EMPTY");
	return answer;
}