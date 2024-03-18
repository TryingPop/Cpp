#include <string>

/*
날짜 : 2024. 3. 18
이름 : 배성훈
내용 : 편지
	글자 한 자 한 자 가로 2cm크기로 적는다
	편지를 가로로만 적을 때,
	축하 문구 message를 적기 위해 필요한 편지지의
	최소 가로 길이를 return 하도록 solution 함수를 구현

	공백도 하나의 문자로 취급
*/

using namespace std;

int solution(string _message)
{

	int answer = _message.length() * 2;
	return answer;
}