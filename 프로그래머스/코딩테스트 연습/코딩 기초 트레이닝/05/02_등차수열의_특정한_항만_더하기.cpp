#include <vector>

/*
날짜 : 2024. 2. 11
이름 : 배성훈
내용 : 등차수열의 특정한 항만 더하기
	시작 값 a와 공차 d, 그리고 bool 배열 included가 주어진다
	bool 배열 값이 true인 인덱스에 해당하는
	등차수열의 합을 반환하는 함수를 구하는 문제

	현재 상황에 맞는 값을 갖게 해야겠다.
*/

using namespace std;

int solution(int _a, int _d, vector<bool> _included)
{

	int answer = 0;
	int num = _a - _d;
	// int num = _a;		// 초기 코드

	// for (int i = 0; i < _included.size(); i++) 
	for (const bool flag : _included)
	{

		num += _d;
		// if (_included[i]) answer += num;
		if (flag) answer += num;
		// num += _d;		// 초기 코드
	}
	return answer;
}