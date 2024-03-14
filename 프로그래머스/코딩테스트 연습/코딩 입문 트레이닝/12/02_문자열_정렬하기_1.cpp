#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 14
이름 : 배성훈
내용 : 문자열 정렬하기 1
	문자열 my_string이 매개변수로 주어질 때,
	my_string 안에 있는 숫자만 골라
	오름차순으로 정렬한 리스트를
	return 하는 solution 함수 구현

	my_string에는 적어도 
	하나의 숫자가 포함되어져 있다
*/

using namespace std;

vector<int> solution(string _my_string)
{

	vector<int> answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c < '0' || c > '9') continue;
		answer.push_back(c - '0');
	}

	sort(answer.begin(), answer.end());

	return answer;
}