#include <vector>
#include <string>

/*
날짜 : 2024. 3. 15
이름 : 배성훈
내용 : 배열 원소의 길이
	문자열 배열 strlist가 매개변수로 주어진다
	strlist 각 원소의 길이를 담은 배열을
	return 하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<string> _strlist)
{

	vector<int> answer;
	answer.reserve(_strlist.size());

	for (const string str : _strlist)
	{

		answer.push_back(str.length());
	}

	return answer;
}