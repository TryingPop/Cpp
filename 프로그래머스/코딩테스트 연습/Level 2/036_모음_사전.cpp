/*
날짜 : 2024. 7. 14
이름 : 배성훈
내용 : 모음 사전
	사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U' 만을 사용하여 만들 수 있는,
	길이 5이하의 모든 단어가 수록되어 있다

	사전에서 첫 번째 단어는 "A"이고
	그 다음은 "AA"이다
	마지막 단어는 "UUUUU"이다

	단어 하나 word가 매개변수로 주어질 때,
	이 단어가 사전에서 몇 번째 단어인지
	return 하도록 solution 함수를 구현

	word의 길이는 1 이상 5이하
	word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있다


	parameter
	"I"


	return
	1563
*/

#include <string>
#include <vector>

#define MAX 5

using namespace std;

vector<char> v;

inline bool DFS(int _depth, string& _cur, string& _find, int& _ret)
{

	/*
	
	6^6 < 100만
	문자열 하나씩 이어붙이며 탐색
	*/

	_ret++;								// 사전 순서
	if (_cur == _find) return true;		// 찾으면 종료
	if (_depth == 5) return false;		// 길이 초과하면 실패

	_cur.push_back(v[0]);
	if (DFS(_depth + 1, _cur, _find, _ret)) return true;	// 찾은 경우 바로 탈출

	for (int i = 1; i < v.size(); i++)
	{

		_cur.back() = v[i];
		if (DFS(_depth + 1, _cur, _find, _ret)) return true;	// 찾은 경우 바로 탈출
	}

	_cur.pop_back();
	return false;
}

int solution(string _word)
{

	int answer = -1;
	v = { 'A', 'E', 'I', 'O', 'U' };
	string temp = "";

	DFS(0, temp, _word, answer);

	return answer;
}