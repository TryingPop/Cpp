#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 22
이름 : 배성훈
내용 : 최댓값 만들기 2
	정수 배열 numbers가 매개변수로 주어질때,
	numbers의 원소 중 2개를 곱해 만들 수 있는
	최댓값을 retun 하는 solution 함수 구현

	numbers의 원소의 절댓값은 1만 이하이다
*/

using namespace std;

int solution(vector<int> _numbers)
{

	int answer = 0;

	// greedy
	// 경우를 분할해서 보면 l과 r중에 최댓값을 가짐을 알 수 있다
	sort(_numbers.begin(), _numbers.end());

	int l = _numbers[0] * _numbers[1];
	int r = _numbers[_numbers.size() - 1] * _numbers[_numbers.size() - 2];

	answer = l < r ? r : l;
	return answer;
}