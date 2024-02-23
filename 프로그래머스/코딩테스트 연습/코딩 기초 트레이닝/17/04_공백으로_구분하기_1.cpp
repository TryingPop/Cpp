#include <string>
#include <vector>

/*
날짜 : 2024. 2. 23
이름 : 배성훈
내용 : 공백으로 구분하기 1
	단어가 공백 한 개로 구분되어 있는 문자열 my_string이
	매개변수로 주어질 때,
	my_string에 나온 단어를 앞에서부터 순서대로 담은 문자열 배열을
	return 하는 solution 함수를 작성
*/

using namespace std;

vector<string> solution(string _my_string)
{

	vector<string> answer;

	string temp;
	for (const char c : _my_string)
	{

		if (c == ' ') 
		{

			answer.push_back(temp);
			temp.clear();
		}
		else 
		{

			temp.push_back(c);
		}
	}

	answer.push_back(temp);

	return answer;
}