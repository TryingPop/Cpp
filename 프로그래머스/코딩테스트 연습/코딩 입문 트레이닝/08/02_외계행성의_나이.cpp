#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 외계행성의 나이
	행성에서 나이는 알파벳으로 말하고 있다
	a = 0, b = 1, ... , j = 9
	10진법으로 사용해서 k이상인 알파벳은 쓰지 않는다

	나이 변수가 정수 age로 주어질 때,
	행성에서 쓰는 나이를 return 하는 solution 함수 구현
*/

using namespace std;

string solution(int _age)
{

	string answer;

	string temp = to_string(_age);
	answer.reserve(temp.length());
	
	for (char c : temp)
	{

		answer.push_back(c - '0' + 'a');
	}

	/*
	while (_age > 0)
	{

		int calc = _age % 10;
		char c = calc + 'a';
		answer.push_back(c);

		_age /= 10;
	}

	reverse(answer.begin(), answer.end());
	*/
	return answer;
}