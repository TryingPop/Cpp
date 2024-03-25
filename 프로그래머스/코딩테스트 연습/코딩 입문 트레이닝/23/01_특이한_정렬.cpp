#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 26
이름 : 배성훈
내용 : 특이한 정렬
	정수 n을 기준으로 n과 가까운 수부터 정렬하려고 한다
	n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 배치
	정수가 담긴 배열 numlist와 정수 n이 주어질 때,
	numlist의 원소를 n으로부터 가까운 순서대로 정렬한
	배열을 return 하도록 solution 함수를 구현

	numlist의 범위는 1이상 10'000 이하
*/

using namespace std;

#if other
int n;

bool comp(int _f, int _b)
{

	int ret = abs(_f - n) - abs(_b - n);
	if (ret == 0) return _f > _b;
	else if (ret < 0) return 1;
	else return 0;
}
#endif

vector<int> solution(vector<int> _numlist, int _n)
{

	vector<int> answer;
	answer.reserve(_numlist.size());

#if other

	// 전역으로 하는 방법
	n = _n;
	sort(_numlist.begin(), _numlist.end(), comp);

	answer = _numlist;
#else
	// 전역으로 int를 빼면 comp함수를 만들어 쉽게 할 수 있다
	// pair를 연습해보기 위해 다른 방법으로 풀었다
	vector<pair<int, int>> temp;
	temp.reserve(_numlist.size());

	for (int i = 0 ; i < _numlist.size(); i++)
	{

		pair<int, int> calc;
		// 차가 같은 경우 작은 경우가 뒤로가게 세팅하려고 2배
		calc.first = 2 * (_numlist[i] - _n);
		if (calc.first < 0) calc.first = -calc.first + 1;
		calc.second = i;
	}

	sort(temp.begin(), temp.end());

	for (pair<int, int>& p : temp) 
	{

		answer.push_back(_numlist[p.second]);
	}
#endif
	return answer;
}