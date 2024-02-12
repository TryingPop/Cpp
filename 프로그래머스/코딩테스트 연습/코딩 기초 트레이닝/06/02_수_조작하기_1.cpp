#include <string>

/*
날짜 : 2024. 2. 12
이름 : 배성훈
내용 : 수 조작하기 1
	정수 n과 문자열 control이 주어진다
	control은 "w", "s", "a", "d"로 이루어진 문자열이다
	control을 앞에서부터 순서대로 n을 바꾼다
		w : n이 1이 커진다
		s : n이 1이 작아진다
		d : n이 10이 커진다
		a : n이 10이 작아진다
	위 규칙에 따라 n을 바꿨을 때, 가장 마지막에 나오는 n의 값을 return하는
	solution 함수를 완성하기

	n은 -10만 ~ 10만사이의 정수
	control의 길이는 1에서 10만 사이

	주석친 코드가 해당코드보다 느리다
*/

using namespace std;

int solution(int _n, string _control) 
{

	int answer;

	answer = _n;

	int calc[128];
	// 프로그래머스에서 사용 안된다;
	// memset(calc, 0, sizeof(calc));
	calc['w'] = 1;
	calc['s'] = -1;
	calc['a'] = 10;
	calc['d'] = -10;

	// calc['w'] = 0;
	// calc['s'] = 0;
	// calc['a'] = 0;
	// calc['d'] = 0;

	for (const char c : _control) 
	{

		// calc[c]++;
		answer += calc[c];
	}

	// answer += calc['w'];
	// answer -= calc['s'];
	// answer += 10 * calc['d'];
	// answer -= 10 * calc['a'];

	return answer;
}