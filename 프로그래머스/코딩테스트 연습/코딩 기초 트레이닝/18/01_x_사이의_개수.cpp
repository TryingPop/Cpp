#include <vector>
#include <string>

/*
날짜 : 2024. 2. 24
이름 : 배성훈
내용 : x 사이의 개수
	문자열 myString이 주어질 때,
	myString을 문자 "x"를 기준으로 나눴을 때 나눠진 문자열
	각각의 길이를 순서대로 저장한 배열을 return 하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(string _myString)
{

	vector<int> answer;

	int len = 0;

	for (const char c : _myString)
	{

		if (c == 'x')
		{

			answer.push_back(len);
			len = 0;
		}
		else len++;
	}

	answer.push_back(len);
	return answer;
}