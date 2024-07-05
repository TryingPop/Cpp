/*
날짜 : 2024. 7. 5
이름 : 배성훈
내용 : 피로도
	XX 게임에는 피로도 시스템이 있다
	일정 피로도를 사용해서 던전을 탐색할 수 있다
	던전 탐색을 시작하기 위한 최소 필요 피로도와
	던전 탐색을 마쳤을 때 소모되는 소모 피로도가 있다

	최소 필요 피로도는 던전을 탐험하기 위해 가지고 있어야 하는
	최소한의 피로도를 의미한다

	소모 피로도는 던전을 탐험한 후 소모되는 피로도를 나타낸다

	이 게임에는 던전이 여러 개 있는데
	한 유저가 던전들을 최대한 많이 탐험하려고 한다

	유저의 현재 피로도 k와 각 던전별 최소 필요 피로도,
	소모 피로도가 담긴 2차원 배열 dungeons가 매개변수로 주어질 때,

	유저가 탐험할 수 있는 최대 던전의 수를
	return 하는 solution 함수 구현

	던전의 개수는 8 이하인 자연수이고
	던전의 소모 피로도는 최소 필요 피로도보다 작거나 같다

	parameter
	80, {{ 80, 20 }, { 50, 40 }, { 30, 10 }}


	return
	3


	sol
	현재 피로도는 80이고 첫 번째 던전을 탐색하기 위한
	최소 필요 피로도는 80이므로 첫 번째 던전을 돌 수 있다
	첫 번째 던전을 탐험하고 나면 소모 피로도는 20이므로
	탐험 후 남은 피로도는 60이 된다

	그리고 세 번째 던전을 탐색한다
	탐험 후 남은 피로도는 50이 된다

	마지막으로 두 번째 던전을 탐색하면
	탐험 후 남은 피로도는 10이고
	더 이상 던전을 돌 수 없다
*/

#include <vector>

using namespace std;

int DFS(int _k, vector<vector<int>>& _arr, vector<bool>& _visit)
{

	int ret = 0;

	for (int i = 0; i < _arr.size(); i++)
	{

		if (_visit[i]) continue;
		_visit[i] = true;

		if (_arr[i][0] <= _k)
		{

			int chk = DFS(_k - _arr[i][1], _arr, _visit) + 1;
			if (ret < chk) ret = chk;
		}

		_visit[i] = false;
	}

	return ret;
}

int solution(int _k, vector<vector<int>> _dungeons)
{

	int answer = -1;

	vector<bool> visit(_dungeons.size(), false);
	answer = DFS(0, _k, _dungeons, visit);
	return answer;
}