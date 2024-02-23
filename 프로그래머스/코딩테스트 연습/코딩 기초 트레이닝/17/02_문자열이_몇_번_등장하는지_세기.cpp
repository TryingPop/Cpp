#include <string>
#include <vector>

/*
날짜 : 2024. 2. 23
이름 : 배성훈
내용 : 문자열이 몇 번 등장하는지 세기
	문자열 myString과 pat이 주어진다
	myString에서 pat이 등장하는 횟수를 
	return 하는 solution 함수 구현
*/
using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	int i = 0;
	while (true)
	{

		i = _myString.find(_pat, i);

		if (i == string::npos) break;

		answer++;
		i++;
	}

	return answer;
}