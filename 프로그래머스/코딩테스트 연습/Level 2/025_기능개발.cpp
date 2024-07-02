/*
날짜 : 2024. 7. 2
이름 : 배성훈
내용 : 기능개발
	기능 개선 작업을 수행 중에 있다
	각 기능은 진도가 100%일 때 서비스에 반영할 수 있다

	그리고 각 기능의 개발속도는 모두 다르기 때문에
	뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고,
	이 때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포된다

	먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수배열
	progresses와 각 작업의 개발 속도가 적힌 정수배열 speeds가
	주어질 때, 각 배포마다 몇 개의 기능이 배포되는지를 return하는 solution 함수 구현

	작업의 개수는 100개 이하이다
	작업 진도는 100 미만의 자연수, 작업속도는 100 이하의 자연수

	배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이뤄진다


	parameter
	{ 93, 30, 55 }, { 1, 30, 5 }


	return
	{ 2, 1 }



	sol
	첫 번째 기능은 7일 뒤에 완성되고
	두 번째 기능은 3일 뒤에 완성된다
	반면 세 번째 기능은 9일뒤에 완성된다
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> _progresses, vector<int> _speeds)
{

	vector<int> answer;

	int len = _progresses.size();

	vector<int>& remain = _progresses;

	for (int i = 0; i < len; i++)
	{

		int r = 100 - _progresses[i];
		int val = r / _speeds[i];
		if (r % _speeds[i]) val++;

		remain[i] = val;
	}

	int idx = 0;
	while (idx < len)
	{

		int val = remain[idx++];
		int cnt = 1;

		while (idx < len && remain[idx] <= val)
		{

			idx++;
			cnt++;
		}

		answer.push_back(cnt);
	}

	return answer;
}