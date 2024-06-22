/*
날짜 : 2024. 6. 23
이름 : 배성훈
내용 : 영어 끝말 잇기
	1부터 n까지 번호가 붙어있는 n명의 사람이
	끝말잇기를 하고 있다

	끝말잇기 규칙은 다음과 같다
		1. 1번 번호부터 순서대로 한 사람씩 차례대로 단어를 말한다
		2. 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작한다
		3. 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 한다
		4. 이전에 등장했던 단어는 사용할 수 없다

	사람의 수 n과 사람들이 순서대로 말한 단어 words가 
	매개변수로 주어질 때, 가장 먼저 탈락하는 사람의 번호와
	그 사람이 자신의 몇 번째 차례에서 탈락하는지를 구해서
	return 하는 solution 함수를 구현

	만약 주어진 단어들로 탈락자가 생기지 않는다면 
	{ 0, 0 }을 return

	모든 단어는 알파벳 소문자로만 이루어져 있다
	n은 2 이상 10이하의 자연수
	
	words의 길이는 n이상 100이하이고
	원소(단어)들의 길이는 2 이상 50이하

	parameter
	2, { "hello", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" }


	return
	{ 3, 3 }
*/

#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(int _n, vector<string> _words)
{

	vector<int> answer(2, 0);

	string before = _words[0];
	map<string, bool> use;
	use[before] = true;

	for (int i = 1; i < _words.size(); i++)
	{

		if (_words[i][0] != before.back() || use[_words[i]])
		{

			// 이전 글자의 끝과 현재의 앞이 안맞는 경우나 이미 사용한 문자면 탈출
			answer[0] = 1 + (i % _n);
			answer[1] = 1 + (i / _n);
			break;
		}

		// 이전글자 갱신 및 사용한 문자 저장
		before = _words[i];
		use[before] = true;
	}

	return answer;
}