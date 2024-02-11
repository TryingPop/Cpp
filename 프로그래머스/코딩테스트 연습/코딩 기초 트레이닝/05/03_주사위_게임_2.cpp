#include <set>

/*
날짜 : 2024. 2. 11
이름 : 배성훈
내용 : 주사위 게임 2
	숫자 1 ~ 6 적힌 육면체 주사위 a, b, c 3개를 굴린다
		a, b, c의 세 숫자가 모두 다른 경우 a + b + c를 반환
		셋 중 어느 두 숫자는 같고 나머지 하나는 다른 경우 ( a + b + c ) * ( a^2 + b^2 + c^2 )
		a, b, c 모두 같은 경우 (a + b + c) * (a ^2 + b^2 + c^2) * ( a^3 + b^3 + c^3 )

	의 값을 반환하는 함수 구현

	set 써서 구현한 사람이 있다
	자료구조 연습할겸 set으로 해본다
*/

using namespace std;

int solution(int _a, int _b, int _c)
{

	int answer;

	answer = _a + _b + _c;
	set<int> s = { _a, _b, _c };

	// if (_a == _b || _a == _c || _b == _a) answer *= (_a * _a + _b * _b + _c * _c);
	if (s.size() >= 2) answer *= (_a * _a + _b * _b + _c * _c);

	// if (_a == _b && _a == _c) answer *= (_a * _a * _a + _b * _b * _b + _c * _c * _c);
	if (s.size() == 3) answer *= answer *= (_a * _a * _a + _b * _b * _b + _c * _c * _c);
	return answer;
}