/*
날짜 : 2024. 7. 1
이름 : 배성훈
내용 : H-Index
	H-Index를 나타내는 값인 h를 찾아야한다
	논문 n편 중, h번 이상 인용된 논문이 h편 이상이고
	나머지 논문이 h번 이하 인용되었다면
	h의 최대값이 H-Index이다

	발표한 논문의 인용 횟수를 담은 배열 citations가
	매개변수로 주어질 때,

	이 과학자의 H-Index를 return 하는
	solution 함수 구현


	parameter
	{ 3, 0, 6, 1, 5 }


	return 
	3


	sol
	1 이상 4개
	2 이상 3개
	3 이상 3개
	4 이상 2개 -> 불가능
	5 이상 2개 -> 불가능
	6 이상 1개 -> 불가능
	7 이상 0개 -> 불가능
	...

	이므로 최대값은 3
*/
#if first
#include <vector>

#define MAX 10'000

using namespace std;

int solution(vector<int> _citations)
{

	int answer = 0;

	// 누적합으로 이상이 몇 개인지 찾기
	vector<int> cnt(MAX + 1, 0);

	for (const int i : _citations)
	{

		cnt[i]++;
	}

	for (int i = MAX - 1; i >= 0; i--)
	{

		cnt[i] = cnt[i] + cnt[i + 1];
	}

	int l = 0;
	int r = MAX;

	// 가능한 경우 이분탐색으로 찾는다
	while (l <= r)
	{

		int mid = (l + r) >> 1;

		// 가능한 경우 높은 범위로 간다
		if (cnt[mid] >= mid) l = mid + 1;
		// 불가능하면 낮은 범위로 간다
		else r = mid - 1;
	}

	answer = l - 1;
	return answer;
}

#else

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _citations) {

	// 모든 원소가 _citations.size() 이상인 경우다
	int answer = _citations.size();

	sort(_citations.begin(), _citations.end(), greater<int>());

	for (int i = 0; i < _citations.size(); i++)
	{

		// 모두 _citations[i] > i + 1 인 경우는 _citations의 최소값이 i 이상인 경우뿐이다
		if (_citations[i] > i + 1) continue;

		// _citations[i] <= i
		// 의미하는게 _citations에 i이상이 i개 있다는 의미이다
		// i를 최대값으로 가질 수 있다
		answer = i;
		break;
	}

	return answer;
}
#endif