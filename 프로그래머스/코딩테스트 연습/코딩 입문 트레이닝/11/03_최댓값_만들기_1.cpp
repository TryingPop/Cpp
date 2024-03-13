#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 13
이름 : 배성훈
내용 : 최댓값 만들기 1
	정수 배열 numbers가 매개변수로 주어질 때,
	numbers의 원소 중 두 개를 곱해 만들 수 있는
	최댓값을 return 하는 solution 함수 구현

	numbers의 원소는 음이아닌 정수이고
	크기는 2 이상이다
*/

using namespace std;

int solution(vector<int> _numbers)
{

	int answer;

	// greedy
	sort(_numbers.begin(), _numbers.end(), greater<int>());
	answer = _numbers[0] * _numbers[1];

	return answer;
}