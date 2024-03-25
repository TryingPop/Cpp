#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 26
이름 : 배성훈
내용 : 등수 매기기
	영어 점수와 수학 점수의 평균 점수를 기준으로
	학생들의 등수를 매기려고 한다

	수학 점수를 담은 2차원 정수 배열 score가
	주어질 때, 영어 점수와 수학 점수의 평균을 기준으로
	매긴 등수를 담은 배열을 return 하도록 solution 함수 구현
*/

using namespace std;

int comp(pair<int, int>& _f, pair<int, int>& _b)
{

	// first 기준 오름차순 정렬
	return _b.first < _f.first;
}

vector<int> solution(vector<vector<int>> _score)
{

	vector<int> answer(_score.size(), 0);

	vector<pair<int, int>> temp;
	temp.reserve(_score.size());

	for (int i = 0; i < _score.size(); i++)
	{

		pair<int, int> c;
		c.first = _score[i][0] + _score[i][1];
		c.second = i;
	}

	sort(temp.begin(), temp.end(), comp);

	int before = -1;
	int rank = 0;
	int add = 1;

	// 랭킹 넣기
	for (pair<int, int>& p : temp)
	{

		if (before != p.first)
		{

			rank += add;
			before = p.first;
			add = 1;
		}
		else add++;

		answer[p.second] = rank;
	}

	return answer;
}