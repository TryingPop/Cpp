#include <string>
#include <vector>

/*
날짜 : 2024. 2. 23
이름 : 배성훈
내용 : 특정 문자열로 끝나는 가장 긴 부분 문자열 찾기
	문자열 myString과 pat이 주어진다
	myString의 부분 문자열 중 pat으로 끝나는 
	가장 긴 부분 문자열을 찾아서 return 하는 
	solution 함수를 구현

	pat은 반드시 myString의 부분 문자열로 주어진다
	pat의 알파벳은 대소문자로 구분해야한다
*/

using namespace std;

string solution(string _myString, string _pat) 
{

	string answer = "";

	int rpos = _myString.rfind(_pat);

	if (rpos != -1) 
	{

		answer.append(_myString.substr(0, rpos));
		answer.append(_pat);
	}

	return answer;
}