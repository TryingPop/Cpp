#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 2. 22
이름 : 배성훈
내용 : A 강조하기
	문자열 myString이 주어진다
	myString에서 알파벳 'a'가 등장하면 전부 'A'로 변환하고
	'A'가 아닌 대소문자 알파벳은 소문자 알파벳으로 변환하여
	return하는 solution 함수 구현
*/

using namespace std;

string solution(string _myString)
{

	string answer = _myString;

	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	for (int i = 0; i < answer.length(); i++)
	{

		if (answer[i] == 'a') answer[i] = 'A';
	}

	return answer;
}