#include <string>


/*
날짜 : 2024. 2. 8
이름 : 배성훈
내용 : 문자열 겹쳐쓰기
	문자열 교체
*/

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
	string answer = "";
#if !other

	answer = my_string.replace(s, overwrite_string.size(), overwrite_string);
#else

{

	answer = my_string;
	int i = 0;
	for (const char c : overwrite_string)
	{

		answer[s + i++] = c;
	}

// 다른 사람 풀이

#endif
	return answer;
}
