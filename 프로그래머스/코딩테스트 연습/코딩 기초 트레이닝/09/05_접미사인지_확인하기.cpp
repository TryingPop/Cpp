#include <vector>
#include <string>

/*
날짜 : 2024. 2. 15
이름 : 배성훈
내용 : 접미사인지 확인하기
	banana의 접미사는
		banana
		anana
		nana
		ana
		na
		a

	문자열 my_string과 is_suffix가 주어질 때,
	is_suffix가 my_string의 접미사라면 1, 아니면 0을 반환하는 함수 구현
*/

using namespace std;

int solution(string _my_string, string _is_suffix)
{

	int answer = 0;
	
	if (_my_string.length() < _is_suffix.length()) return answer;
	/*
	for (int i = 1; i < len; i++)
	{

		if (chk == _is_suffix) 
		{

			answer = 1;
			break;
		}
		chk.erase(0, 1);
	}
	*/

	string chk = _my_string.substr(_my_string.length() - _is_suffix.length());
	answer = chk == _is_suffix;
	return answer;
}