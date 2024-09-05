/*
날짜 : 2024. 9. 5
이름 : 배성훈
내용 : 요격 시스템
	A 나라가 B 나라를 침공했다
	B 나라의 대부분의 전략 자원은 아이기스 군사 기지에 집중되어 있기 때문에
	A 나라는 B 나라의 아이기스 군사 기지에 융단폭격을 가했다

	A나라의 공격에 대항하여 아이기스 군사 기지에서는 무수히 쏟아지는
	폭격 미사일들을 요격하려고 한다

	이곳에는 백발백중을 자랑하는 요격 시스템이 있지만
	운용 비용이 상당하기 때문에 미사일을 최소로 사용해서 
	모든 폭격 미사일을 요격하려고 한다

	A 나라와 B 나라가 싸우고 있는 이 세계는 2차원 공간으로 이루어져 있다
	A나라가 발사한 폭격 미사일은 x축에 평행한 직선 형태의 모양이며
	개구간을 나타내는 정수 쌍 (s, e) 형태로 표현된다

	B 나라는 특정 x 좌표에서 y축에 수평이 되도록 미사일을 발사하며,
	발사된 미사일은 해당 x 좌표에 걸쳐있는 모든 폭격 미사일을 관통하여
	한 번에 요격할 수 있다

	단 개구간 (s, e)로 표현되는 폭격 미사일은 s와 e에서 발사하는
	요격 미사일로는 요격할 수 없다

	요격 미사일은 실수 x인 좌표에서도 발사할 수 있다
	각 포격 미사일의 x좌표 범위 목록 targets가 매개변수로 주어질 때,
	모든 폭격 미사일을 요격하기 위해 필요한 요격 미사일 수의 최솟값을
	return 하는 solution 함수 구현

	targets의 길이는 50만 이하인 자연수
	targets의 각 원소는 { s, e }형태이다
	0 <= s < e <= 100'000'000


	parameter
	{ { 4, 5 }, { 4, 8 }, { 10, 14 }, { 11, 13 }, { 5, 12 }, { 3, 7 }, { 1, 4 } }


	return
	3


	sol
	3.5에서 쏘면 { 1, 4 }, { 3, 7 } 이 요격된다
	4.5에서 쏘면 { 4, 5 }, { 4, 8 } 이 요격된다
	11.5에서 쏘면 { 10, 14 }, { 11, 13 }, { 5, 12 } 이 요격된다
	3개가 최소이다
*/

#include <vector>
#include <algorithm>

using namespace std;

bool MyComp(vector<int>& _f, vector<int>& _b)
{

	if (_f[1] != _b[1]) return _f[1] < _b[1];
	return _f[0] < _b[0];
}

int solution(vector<vector<int>> _targets)
{

	/*
	
	그리디 문제
	*/

	int answer = 0;
	sort(_targets.begin(), _targets.end(), MyComp);

	int t = -1;
	for (vector<int>& target : _targets)
	{

		if (target[0] < t) continue;
		t = target[1];
		answer++;
	}

	return answer;
}