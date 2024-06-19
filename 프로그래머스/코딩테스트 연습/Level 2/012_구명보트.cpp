/*
날짜 : 2024. 6. 19
이름 : 배성훈
내용 : 구명보트
	구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고 무게 제한도 있다
	구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 한다

	사람들의 몸무게를 담은 배열 people과 
	구명보트의 무게 제한 limit가 매개변수로 주어질 때,
	모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을
	return 하는 solution 함수 구현

	구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어진다

	parameter
	{ 70, 50, 80, 50 }


	return
	3
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _people, int _limit)
{

	int answer = _people.size();

	sort(_people.begin(), _people.end());

	int l = 0;
	int r = _people.size() - 1;

	while (l < r)
	{

		int cur = _people[l] + _people[r];
		if (cur <= _limit)
		{

			l++;
			r--;
			answer--;
		}
		else r--;
	}

	return answer;
}