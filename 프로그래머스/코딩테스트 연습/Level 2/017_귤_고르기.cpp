/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : 귤 고르기
	한 상자에 담으려는 귤의 개수 k와,
	수확한 귤의 크기를 담은 배열 tangerine
	이 매개변수로 주어질 때,

	k개를 고를 때 크기가 서로 다른 종류의 수의 
	최솟값을 return 하는 solution 함수를 구현

	tangerine의 원소는 1000만 이하의 자연수이고,
	k <= tangerine의 길이이고, tangerine의 길이는 10만 이하이다

	parameter
	6, { 1, 3, 2, 5, 4, 5, 2, 3 }


	return
	3


	solve
	1, 4는 1개씩 있고
	2, 3, 5의 귤이 각각 2개씩 있다
	다른 크기는 없다

	2, 4, 5를 모두 담으면 6개가되고
	서로 다른 크기 종류는 3개로 최소가 된다
	그래서 3개 반환
*/

#include <vector>
#include <algorithm>

using namespace std;

void CompactVec(vector<int>& _vec)
{

	sort(_vec.begin(), _vec.end());

	int val = 0;
	int before = 0;

	for (int i = 0; i < _vec.size(); i++)
	{

		if (before != _vec[i])
		{

			before = _vec[i];
			val++;
		}

		_vec[i] = val;
	}
}

void CountVec(const vector<int>& _vec, vector<int>& _ret)
{

	for (const int num : _vec)
	{

		_ret[num]++;
	}
}

int GetRet(vector<int>& _cnt, int _k) 
{

	// Greedy
	int ret = 0;
	sort(_cnt.begin(), _cnt.end(), greater<int>());
	for (const int num : _cnt)
	{

		_k -= num;
		ret++;
		if (_k <= 0) break;
	}

	return ret;
}

int solution(int _k, vector<int> _tangerine)
{

	int answer = 0;

	CompactVec(_tangerine);

	vector<int> cnt(_tangerine.back() + 1, 0);
	CountVec(_tangerine, cnt);

	answer = GetRet(cnt, _k);

	return answer;
}