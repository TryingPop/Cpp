#include <vector>

/*
날짜 : 2024. 3. 29
이름 : 배성훈
내용 : 연속된 수의 합
	두 정수 num과 total이 주어질 때,
	연속된 수 num개를 더한 값이 total이 될 때,
	정수 배열을 오름차순으로 담아 return 하도록
	solution 함수를 구현

	num은 1 ~ 100사이의 자연수이고,
	total은 0 이상 1000 이하의 정수이다
*/

using namespace std;

vector<int> solution(int _num, int _total)
{

	vector<int> answer;
	answer.reserve(_num);

	// 우선 해는 무조건 존재한다!
	_total *= 2;
	int calc = _total / _num;

	// mid + r : 왼쪽 끝값이 되게 할 예정
	int mid;
	int r;

	if (_num & 1)
	{

		// 홀수
		mid = calc / 2;
		r = _num / 2;
		r = -r;
	}
	else
	{

		// 짝수
		mid = 1 + calc / 2;
		r = _num / 2;
		r = -r;
	}

	for (int i = 0; i < _num; i++)
	{

		answer.push_back(mid + i + r);
	}

	return answer;
}