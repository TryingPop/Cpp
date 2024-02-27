#include <vector>
#include <algorithm>

/*
날짜 : 2024. 2. 27
이름 : 배성훈
내용 : 전국 대회 선발 고사
	각 학생들의 선발 고사 등수를 담은 정수 배열 rank와
	전국 대회 참여 가능 여부가 담긴 bool 배열 attendance가 주어진다
	0번부터 n - 1번까지 n명의 학생 중 전국 대회 참여 가능하고 
	등수가 높은 3명을 선발

	전국대회에서 선발된 학생 번호들을 등수가 높은 순서대로
	각각 a, b, c라 할 때, 10'000 * a + 100 * b + c를
	return하는 solution 함수 구현
*/

using namespace std;

int comp(pair<int, int> _calc1, pair<int, int> _calc2)
{

	return _calc1.first < _calc2.first;
}

int solution(vector<int> _rank, vector<bool> _attendance)
{

	int answer = 0;
	vector<pair<int, int>> temp;
	temp.reserve(_rank.size());

	for (int i = 0; i < _attendance.size(); i++) 
	{

		if (_attendance[i]) temp.push_back({ _rank[i], i });
	}

	sort(temp.begin(), temp.end(), comp);

	answer = 10'000 * temp[0].second + 100 * temp[1].second + temp[2].second;
	return answer;
}