#include <vector>
#include <string>
#include <algorithm>

/*
날짜 : 2024. 2. 24
이름 : 배성훈
내용 : 문자열 잘라서 정렬하기
	문자열 myString이 주어진다
	"x"를 기준으로 해당 문자열을 잘라내 배열을 만든 후
	사전순으로 정렬한 배열을
	return 하는 solution 함수를 구현

	단, 빈 문자열은 반환할 배열에 넣지 않는다
*/

using namespace std;

vector<string> solution(string _myString)
{

	vector<string> answer;

	string temp;
	for (const char c : _myString)
	{

		if (c == 'x')
		{

			if (!temp.empty())
			{

				answer.push_back(temp);
				temp.clear();
			}
		}
		else temp.push_back(c);
	}

	if (!temp.empty()) answer.push_back(temp);

	sort(answer.begin(), answer.end());
	return answer;
}