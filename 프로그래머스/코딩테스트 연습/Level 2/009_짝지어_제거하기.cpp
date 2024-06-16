/*
날짜 : 2024. 6. 16
이름 : 배성훈
내용 : 짝지어 제거하기
	알파벳 소문자로 이루어진 문자열이 주어진다
	문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾는다
	그다음에 그 둘을 제거한 뒤 앞뒤로 문자열을 이어붙인다
	이 과정을 반복해서 문자열을 모두 제거한다면 짝지어 제거하기가 종료된다

	문자열 s가 주어졌을 때,
	짝지어 제거하기를 성공적으로 수행할 수 있으면 1을
	없으면 0을 return 하는 solution 함수 구현


	parameter
	baabaa


	return
	1
*/

#include <string>

using namespace std;

int solution(string _s)
{

	int answer = 1;
	int len = 0;

	// Stack
	for (const char c : _s)
	{

		if (len == 0)
		{

			_s[len++] = c;
			continue;
		}

		if (c == _s[len - 1]) len--;
		else _s[len++] = c;
	}

	if (len) answer = 0;

	return answer;
}