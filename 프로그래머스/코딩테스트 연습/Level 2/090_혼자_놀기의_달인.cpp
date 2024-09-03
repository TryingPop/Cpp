/*
날짜 : 2024. 9. 3
이름 : 배성훈
내용 : 혼자 놀기의 달인
	숫자 카드 더미에는 카드가 총 100장 있으며,
	각 카드에는 1부터 100까지 숫자가 하나씩 적혀 있다
	2 이상 100 이하의 자연수를 하나 정해
	그 수보다 작거나 같은 숫자 카드들을 준비하고,
	준비한 카드의 수만큼 작은 상자를 준비하면 
	게임을 시작할 수 있으며 게임방법은 다음과 같다

	준비된 상자에 카드를 한 장씩 넣고,
	상자를 무작위로 섞어 일렬로 나열한다
	상자가 일렬로 나열되면 상자가 나열된 순서에 따라
	1번부터 순차적으로 증가하는 번호를 붙인다

	그 다음 임의의 상자를 하나 선택하여
	선택한 상자 안의 숫자 카드를 확인한다
	다음으로 확인한 카드에 적힌 번호에 해당하는
	상자를 열어 안에 담긴 카드에 적힌 숫자를 확인한다
	마찬가지로 숫자에 해당하는 번호를 가진 상자를 계속해서 열어가며,
	열어야 하는 상자가 이미 열려있을 때까지 반복한다

	이렇게 연 상자들은 1번 상자 그룹이다
	이제 1번 상자 그룹을 다른 상자들과 섞이지 않도록 따로 둔다
	만약 1번 상자 그룹을 제외하고 남는 상자가 없으면
	그대로 게임이 종료 되며, 이때 획득하는 점수는 0점이다

	그렇지 않다면 남은 상자 중 다시 임의의 상자 하나를 골라
	같은 방식으로 이미 열려 있는 상자를 만날 때까지 상자를 연다
	이렇게 연 상자들은 2번 상자 그룹이다

	1번 상자 그룹에 속한 상자의 수와 
	2번 상자 그룹에 속한 상자의 수를 곱한 값이
	게임의 점수이다

	상자 안에 들어있는 카드 번호가 순서대로 담긴 배열 
	cards가	매개변수로 주어질 때,
	이 게임에서 얻을 수 있는 최고 점수를 구해서
	return 하는 solution 함수 구현

	cards의 길이 2 이상 100 이하 자연수
	cards의 원소는 cards의 길이 이하인 임의의 자연수
	cards에는 중복되는 원소가 존재하지 않는다
	cards[i]는 i + 1번 상자에 담긴 카드에 적힌 숫자를 의미한다

	parameter
	{ 8, 6, 3, 7, 2, 5, 1, 4 }


	return
	12


	sol
	1, 4, 7, 8을 1번 상자 그룹,
	2, 5, 6을 2번 상자 그룹이라하면
	최고 점수 12점을 얻을 수 있다
*/

#include <vector>
#include <algorithm>

using namespace std;

inline int DFS(int _n, vector<int>& _cards, vector<bool>& _visit)
{

	/*
	
	사이클의 길이 찾기
	*/
	_visit[_n] = true;
	int ret = 1;
	int next = _cards[_n] - 1;
	if (_visit[next]) return ret;
	ret += DFS(next, _cards, _visit);

	return ret;
}

int solution(vector<int> _cards)
{

	/*
	
	그래프 문제
	*/

	vector<bool> visit(_cards.size(), false);
	vector<int> group;

	// 이어진 그룹 찾기
	for (int i = 0; i < _cards.size(); i++)
	{

		if (visit[i]) continue;
		int num = DFS(i, _cards, visit);
		group.push_back(num);
	}

	// 연산용으로 0 추가
	group.push_back(0);
	sort(group.begin(), group.end(), greater<int>());

	int answer = group[0] * group[1];
	return answer;
}