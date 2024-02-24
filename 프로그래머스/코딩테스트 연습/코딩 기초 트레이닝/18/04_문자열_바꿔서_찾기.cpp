#include <string>
#include <vector>

/*
날짜 : 2024. 2. 24
이름 : 배성훈
내용 : 문자열 바꿔서 찾기
	문자 "A"와 "B"로 이루어진 문자열 myString과
	pat가 주어진다

	myString의 "A"를 "B"로 "B"를 "A"로 바꾼 문자열의
	연속하는 부분 문자열 중 pat이 있으면
	1을 아니면 0을 return 하는 solution 함수 구현
*/

using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	string temp;
	temp.reserve(_myString.length());

	for (const char c : _myString)
	{

		if (c == 'A') temp.push_back('B');
		else temp.push_back('A');
	}

	answer = temp.find(_pat) != string::npos;
	return answer;
}