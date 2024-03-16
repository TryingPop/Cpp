#include <string>

/*
날짜 : 2024. 3. 16
이름 : 배성훈
내용 : 암호 해독
	암호화된 문자열 cipher,
	code의 배수 번째 글자만 진짜 암호

	문자열 cipher와 정수 code가 매개변수로 주어질 때,
	해독된 암호 문자열을 return 하는
	solution 함수 구현
*/

using namespace std;

string solution(string _cipher, int _code)
{

	string answer;
	answer.reserve(1 + _cipher.length() / _code);

	for (int i = _code - 1; i < _cipher.length(); i += _code)
	{

		answer.push_back(_cipher[i]);
	}

	return answer;
}