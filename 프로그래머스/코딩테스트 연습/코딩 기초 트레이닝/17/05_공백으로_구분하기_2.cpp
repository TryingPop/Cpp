#include <string>
#include <vector>

/*
날짜 : 2024. 2. 23
이름 : 배성훈
내용 : 공백으로 구분하기 2
	단어가 공백 한 개 이상으로 구분되어 있는 문자열 my_string이 매개변수로 주어질 때,
	my_string에 나온 단어를 앞에서부터 순서대로 담은 문자열 배열을
	return하는 solution 함수를 작성
*/

using namespace std;

vector<string> solution(string _my_string)
{

	vector<string> answer;

	string temp;
	char before = '\0';
	
	for (const char c : _my_string)
	{

		if (c != ' ')
		{

			if (before == ' ' && !temp.empty()) 
			{

				answer.push_back(temp);
				temp.clear();
			}

			temp.push_back(c);
		}

		before = c;
	}

	if (!temp.empty()) answer.push_back(temp);
	return answer;
}