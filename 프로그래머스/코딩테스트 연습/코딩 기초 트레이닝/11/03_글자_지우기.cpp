#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 2. 17
이름 : 배성훈
내용 : 글자 지우기
	문자열 my_string과 정수배열 indices가 주어질 때,
	my_string에서 indices의 원소에 해당하는 인덱스의 글자를 지우고
	이어 붙인 문자열을 return하는 solution 함수를 작성

	my_string은 대소문자 알파벳으로만 이루어져 있다!
*/

using namespace std;

string solution(string _my_string, vector<int> _indices)
{

	string answer;

#if Slow
	answer = _my_string;

	// 오름 차순 정렬
	sort(_indices.begin(), _indices.end(), greater<int>());

	// 뒤에서부터 하나씩 제거
	for (const int indice : _indices)
	{

		answer.erase(indice);
	}
#else

	string temp = _my_string;
	answer.reserve(_my_string.length() - _indices.size());

	for (const int indice : _indices)
	{

		temp[indice] = ' ';
	}

	for (const char c : temp)
	{

		if (c == ' ') continue;
		answer.push_back(c);
	}
#endif
	return answer;
}