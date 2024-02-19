#include <string>
#include <vector>

/*
날짜 : 2024. 2. 19
이름 : 배성훈
내용 : 왼쪽 오른쪽
	문자열 리스트 str_list에는 "u", "d", "l", "r"로 이루어진 리스트이다
	str_list에서 "l"과 "r" 중 먼저 나오는 문자열이 "l"이라면
	해당 문자열을 기준으로 왼쪽에 있는 문자열들을 순서대로 담은 리스트를,
	먼저 나오는 문자열이 "r"이라면 해당 문자열을 기준으로 오른쪽에 있는 문자열들을 순서대로 담은
	리스트를 return 하도록 solution 함수를 구현
	"l", "r"이 없다면 빈 리스트를 반환
*/

using namespace std;

vector<string> solution(vector<string> _str_list)
{

	vector<string> answer;

	int pos = -1;
	bool isL = false;
	for (int i = 0; i < _str_list.size(); i++)
	{

		if (_str_list[i] == "r")
		{

			isL = false;
			pos = i;
			break;
		}
		else if (_str_list[i] == "l")
		{

			isL = true;
			pos = i;
			break;
		}
	}

	if (pos != -1)
	{

		if (isL)
		{

			for (int i = 0; i < pos; i++)
			{

				answer.push_back(_str_list[i]);
			}

			// answer.assign(_str_list.begin(), _str_list.begin() + pos);
		}
		else 
		{

			for (int i = pos + 1; i < _str_list.size(); i++)
			{

				answer.push_back(_str_list[i]);
			}

			// answer.assign(_str_list.begin() + pos + 1, _str_list.end());
		}
	}
	return answer;
}
