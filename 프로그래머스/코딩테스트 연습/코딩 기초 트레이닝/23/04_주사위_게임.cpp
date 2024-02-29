/*
날짜 : 2024. 2. 29
이름 : 배성훈
내용 : 주사위 게임 1
	1 ~ 6까지 적힌 주사위 2개가 있다
	두 주사위를 굴렸을 때 나온 값을 각각 a, b

	a, b 가 모두 홀수면, a^2 + b^2의 점수를 얻는다
	a, b 중 하나만 홀수면 2 * (a + b)의 점수를 얻는다
	a, b 둘 다 짝수면 |a - b| 의 점수를 얻는다 여기서 |c|는 c의 절댓값을 의미한다

	두 정수 a, b가 주어질 때,
	얻는 점수를 return 하는 solution 함수를 구현
*/

// using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;
	
	if ((_a & 1) && (_b & 1)) answer = _a * _a + _b * _b;
	else if ((_a & 1) || (_b & 1)) answer = 2 * (_a + _b);
	else answer = _a < _b ? _b - _a : _a - _b;

	return answer;
}