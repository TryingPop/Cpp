#include <string>
#include <vector>

/*
날짜 : 2024. 2. 11
이름 : 배성훈
내용 : 코드 처리하기
	문자열 code를 입력받는다
	문자열을 하나씩 읽어가는데, 
	
	모드에 맞춰 문자열을 반환한다
	모드는 2가지가 있다

	모드 0 : 문자열의 짝수 부분만 출력
	모드 1 : 문자열의 홀수 부분만 출력

	초기 모드는 0이며, 문자열을 하나씩 읽어나가는데 "1"을 읽는 순간 모드를 변경한다
	그리고 다 읽었을 때, 문자열의 길이가 0이면, EMPTY를 반환하는 문제

	length() == 0이 아닌 empty 메서드를 이용해 판별 가능하다
*/

using namespace std;

string solution(string _code) 
{

	string answer;

	answer.reserve(_code.size() / 2);
	int mode = 0;
	
	for (int i = 0; i < _code.length(); i++)
	{

		const char c = _code[i];
		if (c == '1') 
		{ 
			
			mode = mode ? 0 : 1; 
			continue;
		}

		if ((i & 1) == mode) answer.push_back(c);
	}

	if (answer.empty()) answer = "EMPTY";
	return answer;
}