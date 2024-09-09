/*
날짜 : 2024. 9. 9
이름 : 배성훈
내용 : 퍼즐 게임 챌린지
	순서대로 n개의 퍼즐을 제한 시간 내에 풀어야 하는 퍼즐 게임을 하고 있다
	각 퍼즐은 난이도와 소요 시간이 정해져 있다
	당신의 숙련도에 따라 퍼즐을 풀 때 풀리는 횟수가 바뀐다
	현재 퍼즐의 난이도를 diff, 현재 퍼즐의 소요 시간을 time_cur,
	이전 퍼즐의 소요 시간을 time_prev, 당신의 숙련도를 level이라 할 때,
	게임은 다음과 같이 진행된다

	diff <= level이면 퍼즐을 틀리지 않고 
	time_cur 만큼의 시간을 사용하여 해결한다

	diff > level이면, 퍼즐을 총 diff - level번 틀린다
	퍼즐을 틀릴 때마다, time_cur만큼의 시간을 사용하며,
	추가로 time_prev만큼의 시간을 사용해 이전 퍼즐을 다시 풀어야 한다
	이전 퍼즐을 다시 풀 때는 이전 퍼즐의 난이도에 상관없이 틀리지 않는다
	diff - level번 틀린 이후에 다시 퍼즐을 풀면 time_cur 만큼의 시간을 사용하여
	퍼즐을 해결한다

	퍼즐 게임에는 제한 시간 limit이 존재한다
	제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값을 구하려고 한다
	난이도, 소요시간은 모두 양의 정수며, 숙련도도 양의 정수여야 한다

	퍼즐을 난이도를 순서대로 담은 1차원 배열 diffs,
	퍼즐의 소요 시간을 순서대로 담은 1차원 정수 배열 times,
	전체 제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값을 정수로
	return 하는 solution 함수 구현

	diffs의 길이는 times의 길이와 같고 30만 이하의 자연수이다
	diffs[i]의 값은 10만 이하의 자연수이고,
	times[i]는 1만 이하의 자연수이다

	limit의 값은 10^15 이하의 자연수이다
	제한 시간 내에 퍼즐을 모두 해결할 수 있는 경우만 주어진다

	parameter
	{ 1, 5, 3 }, { 2, 4, 7 }, 30


	return
	3


	sol
	level이 높으면 높을수록 틀리는 횟수가 
	이전 level보다 적거나 같아지므로 시간이 덜 걸린다
	
	level이 2인 경우를 보자
	1번은 틀리지 않고 2초의 시간으로 통과한다

	2번의 경우 난이도가 5이므로 3번틀리고
	3 x 6 + 4 = 22초의 시간으로 통과한다

	3번의 경우 난이도가 3이므로 1번 틀리고
	11 + 7 = 18초의 시간으로 통과한다

	그래서 총 2 + 22 + 18 = 42초가 걸려
	제한시간 30초 내에 통과하지 못한다

	level이 3인 경우
	1번은 틀리지 않고 2초의 시간으로 통과한다

	2번의 경우는 난이도가 5이므로 5 - 3 = 2번 틀리고
	틀릴 때마다 2 + 4 = 6초의 시간을 소요한다
	그래서 2 x 6 + 4 = 16초의 시간이 걸린다

	3번의 경우 7초의 시간이 걸린다

	그래서 2 + 16 + 7 = 25초로
	제한시간 30초 내에 통과한다



	그래서 최소 레벨은 3이다
*/

#include <vector>
#define ll long long

using namespace std;

inline ll GetTime(const vector<int>& _diffs, const vector<int>& _times, const ll _lvl)
{

	/*

	lvl에 따른 총 시간 계산
	*/
	ll ret = 0;
	for (int i = 0; i < _diffs.size(); i++)
	{

		ll prev = ((i == 0) ? 0 : _times[i - 1]);
		if (_diffs[i] <= _lvl) ret += _times[i];
		else ret += _times[i] + (_diffs[i] - _lvl) * (prev + _times[i]);
	}

	return ret;
}

inline int BinarySearch(const vector<int>& _diffs, const vector<int>& _times, const ll _limit)
{

	/*

	lvl을 이분 탐색
	*/
	int l = 1, r = 1e5;

	while (l <= r)
	{

		int mid = (l + r) >> 1;

		if (GetTime(_diffs, _times, mid) <= _limit)
			r = mid - 1;

		else l = mid + 1;
	}

	return r + 1;
}

int solution(vector<int> _diffs, vector<int> _times, ll _limit)
{

	/*

	이분 탐색
	*/
	int answer = BinarySearch(_diffs, _times, _limit);
	return answer;
}