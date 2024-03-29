#include <vector>

/*
날짜 : 2024. 3. 29
이름 : 배성훈
내용 : 다음에 올 숫자
	등차수열 혹은 등비수열 common이 매개변수로 주어질 때,
	마지막 원소 다음으로 올 숫자를 return 하도록
	solution 함수를 구현

	등차수열 혹은 등비수열인 경우는 없다
	등비수열의 경우 공비는 0이아닌 정수!
*/

using namespace std;

int solution(vector<int> _common)
{

	int answer;

	int d = _common[1] - _common[0];
	int r = _common[1] / _common[0];

	// 등차수열인 경우 공차를 더하고
	if (d == _common[2] - _common[1]) answer = _common.back() + d;
	// 등비 수열이면 공비를 곱한다
	else answer = _common.back() * r;

	return answer;
}