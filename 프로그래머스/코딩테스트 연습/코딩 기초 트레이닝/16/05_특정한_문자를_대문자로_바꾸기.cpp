#include<string>
#include<vector>
#include<algorithm>

/*
날짜 : 2024. 2. 22
이름 : 배성훈
내용 : 특정한 문자를 대문자로 바꾸기
	영소문자로 이루어진 문자열 my_string
	영소문자 1글자로 이루어진 문자열 alp가
	매개변수로 주어질 때
	my_string에서 alp에 해당하는 모든 문자를 대문자로 바꾼 문자열을 
	return하는 solution 함수를 작성
*/
using namespace std;

string solution(string _my_string, string _alp)
{

	string answer = _my_string;

	for (int i = 0; i < _my_string.length(); i++)
	{

		if (answer[i] == _alp[0]) answer[i] += 'A' - 'a';
	}

	return answer;
}