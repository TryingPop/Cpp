#include <string>
#include <vector>
#define ALPHABET 26

/*
날짜 : 2024. 2. 17
이름 : 배성훈
내용 : 문자 개수 세기
	알파벳 대소문자로만 이루어진 문자열 my_string이 주어질 때, 
	my_string에서 'A'의 개수, my_string에서 'B'의 개수,...
	, my_string에서 'Z'의 개수, my_string에서 'a'의 개수,
	my_string에서 'b'의 개수, ..., my_string에서 'z'의 개수를
	순서대로 담은 길이 52 정수 배열을 return 하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(string _my_string)
{

	// vector<int> answer(ALPHABET * 2, 0);
	vector<int> answer;
	answer.assign(ALPHABET * 2, 0);

	for (const char c : _my_string)
	{

		int idx;
		if (c > 'Z') idx = c - 'a' + ALPHABET;
		else c - 'A';

		answer[idx]++;
	}

	return answer;
}