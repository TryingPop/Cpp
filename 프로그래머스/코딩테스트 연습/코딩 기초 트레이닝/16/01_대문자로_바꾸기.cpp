#include <string>
#include <vector>
#if !first
#include <algorithm>
#endif
/*
날짜 : 2024. 2. 22
이름 : 배성훈
내용 : 대문자로 바꾸기
	알파벳으로 이루어진 문자열 myString이 주어진다
	모든 알파벳을 대문자로 변환하여 return하는 solution 함수 구현
*/

using namespace std;

string solution(string _myString)
{

	string answer;
#if first
	answer.reserve(_myString.size());

	int calc = 'A' - 'a';
	for (int i = 0; i < _myString.length(); i++)
	{

		if (_myString[i] > 'Z') answer.push_back(_myString[i] + calc);
		else answer.push_back(_myString[i]);
	}
#else
	answer = _myString;
	transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
	
#endif
	return answer;
}