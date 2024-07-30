/*
날짜 : 2024. 7. 30
이름 : 배성훈
내용 : 소수 찾기
	한자리 숫자가 적힌 종이 조각이 흩어져있다
	흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 한다

	각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때,
	종이 조각으로 만들 수 있는 서로 다른 소수가 몇 개인지 
	return 하는 solution 함수 구현

	numbers의 길이 1 이상 7 이하인 문자열
	numbers는 0 ~ 9 까지 숫자만으로 이루어져 있다
	013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져 있다는 의미

	parameter
	011


	return
	2


	sol
	11, 101 을 만들 수 있다
*/

#include <string>
#include <vector>
#include <set>

#define ll long long

using namespace std;

inline bool IsPrime(int _num)
{

	/*
	
	에라토스 테네스 체로 소수 판정
	*/
	if (_num < 2) return false;

	for (ll i = 2; i * i <= _num; i++)
	{

		if (_num % i) continue;

		return false;
	}

	return true;
}

inline void DFS(int _depth, vector<int>& _cnt, set<int>& _ret, set<int>& _visit, int _num)
{

	/*
	
	만들어진 소수를 use에 저장
	*/

	if (_visit.count(_num)) return;
	_visit.insert(_num);

	if (IsPrime(_num)) _ret.insert(_num);
	if (!_depth) return;

	for (int i = 9; i >= 0; i--)
	{

		if (!_cnt[i]) continue;
		_cnt[i]--;

		DFS(_depth - 1, _cnt, _ret, _visit, _num * 10 + i);
		_cnt[i]++;
	}
}

int solution(string _numbers)
{

	/*
	
	브루트 포스
	*/
	int answer = 0;
	vector<int> cnt(10, 0);			// 숫자 개수 확인
	set<int> ret;					// 만들 수 있는 소수 모음
	set<int> visit;					// 재방문 방지
	int dep = _numbers.length();

	for (const char c : _numbers)
	{

		cnt[c - '0']++;
	}

	DFS(dep, cnt, ret, visit, 0);
	answer = ret.size();
	return answer;
}