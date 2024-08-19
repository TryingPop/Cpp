/*
날짜 : 2024. 8. 19
이름 : 배성훈
내용 : 줄 서는 방법
	n명의 사람이 일렬로 줄을 서고 있다
	n명의 사람들에게는 각각 1번부터 n번까지 번호가 매겨져 있다
	n명이 사람을 줄을 서는 방법은 여러가지 방법이 있다

	사람의 수 n과 자연수 k가 주어질 때,
	사람을 나열하는 방법을 사전순으로 나열 했을 때,
	k번째 방법을 return 하는 solution 함수를 구현

	n은 20이하의 자연수
	k는 n! 이하의 자연수


	parameter
	3, 5


	return
	{ 3, 1, 2 }


	sol
	3명의 사람이 줄을 서는 방법은 다음과 같다
		1,	2,	3
		1,	3,	2
		2,	1,	3
		2,	3,	1
		3,	1,	2
		3,	2,	1

	여기서 사전순으로 5번째는
	{ 3, 1, 2}가 된다
*/

#include <vector>

#define ll long long

using namespace std;

inline vector<ll> GetChkDigitVec(int _n)
{


	/*
	
	자리 별로 숫자가 몇번째마다 바뀌는지 확인하는 
	숫자를 벡터로 반환

	i번째 자리는 (n - i - 1)! 마다 바뀐다
	그래서 (n - 1)!, (n - 2)!, ..., 0! 순으로 담는다
	*/
	vector<ll> ret;

	ret.push_back(1);

	ll cur = 1;

	for (int i = 1; i < _n; i++)
	{

		cur *= i;
		ret.push_back(cur);
	}

	for (int i = 0; i < ret.size(); i++)
	{

		int j = ret.size() - 1 - i;
		if (j <= i) break;
		ll temp = ret[i];
		ret[i] = ret[j];
		ret[j] = temp;
	}

	return ret;
}

inline int GetNum(int _nth, vector<bool>& _use)
{

	/*
	
	남아있는 사람 중 nth 번째 사람 반환
	*/
	for (int i = 1; i < _use.size(); i++)
	{

		if (_use[i]) continue;
		_nth--;

		if (_nth) continue;
		_use[i] = true;
		return i;
	}

	// 해당 문제에서 여기로 안온다
	return -1;
}

vector<int> solution(int _n, ll _k)
{

	vector<int> answer;

	vector<ll> chkDigitVec = GetChkDigitVec(_n);
	vector<bool> use(_n + 1, false);

	_k--;

	for (int i = 0; i < _n; i++)
	{

		// 자리 별로 사람을 세운다
		int nth = _k / chkDigitVec[i];
		_k -= nth * chkDigitVec[i];

		nth++;
		int add = GetNum(nth, use);
		answer.push_back(add);
	}

	return answer;
}