#include <string>
#include <vector>
#include <map>

/*
날짜 : 2024. 2. 12
이름 : 배성훈
내용 : 수 조작하기 2
	정수 배열 numLog, 처음에 numLog[0]에서부터 시작해
	"w", "s", "a", "d"로 이루어진 문자열을 입력받아 다음과 같은 조작을한다
	"w" : 수에 1을 더한다
	"s" : 수에 1을 뺀다
	"d" : 수에 10을 더한다
	"a" : 수에 10을 뺀다

	그리고 매번 조작을 할 때마다 결과값을 기록한 정수 배열이 numLog
	numLog[i]는 numLog[0]로부터 총 i번 조작을 가한 결과가 저장

	numLog에 대해 조작을 위해 입력받은 문자열을 return하는 solution 함수를 완성하기
	
	맵을 연습할겸 썼다
*/

using namespace std;

string solution(vector<int> _numLog) 
{

	// 널문자 존재
	string answer = "";
	answer.reserve(_numLog.size());
	int before = _numLog[0];

	map<int, char> m = { { -10, 'a'}, { -1, 's' }, { 1, 'w' }, { 10, 'd' } };
	for (const int c : _numLog)
	{

		int calc = c - before;
		
		answer.push_back(m[calc]);
		/*
		switch (calc)
		{

			case -1:
				answer.push_back('s');
				break;
			case 1:
				answer.push_back('w');
				break;

			case 10:
				answer.push_back('d');
				break;
			case -10:
				answer.push_back('a');
				break;
		}
		*/
		before = c;
	}

	// 널 문자 제거
	answer.erase(0, 1);
	return answer;
}