#include <string>
#include <vector>

/*
날짜 : 2024. 2. 15
이름 : 배성훈
내용 : 부분 문자열 이어 붙여 문자열 만들기
	길이가 같은 문자열 배열 my_strings와 이차원 정수 배열 parts가 매개변수로 주어진다
	parts[i]는 { s, e }의 형태이고, my_string[i]의 인덱스 s부터 e까지의 부분문자열의 의미
	각 my_strings의 원소 parts에 해당하는 부분 문자열을 순서대로 이어 붙인 문자열을 return 하는
	solution 함수 구현하기
*/

using namespace std;

string solution(vector<string> _my_strings, vector<vector<int>> _parts)
{

	string answer = "";

	for (int i = 0; i < _my_strings.size(); i++)
	{

		/*
		for (int j = _parts[i][0]; j <= _parts[i][1]; j++)
		{

			answer.push_back(_my_strings[i][j]);
		}
		*/

		answer.append(_my_strings[i].substr(_parts[i][0], _parts[i][1] - _parts[i][0] + 1));
	}
	return answer;
}