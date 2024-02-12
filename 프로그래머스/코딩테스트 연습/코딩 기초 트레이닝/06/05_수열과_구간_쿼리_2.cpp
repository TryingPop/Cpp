#include <vector>

// #define MAX 1'000'001
/*
날짜 : 2024. 2. 12
이름 : 배성훈
내용 : 수열과 구간 쿼리 2
	정수 배열 arr과 2차원 정수 배열 queries가 주어진다
	queries의 원소는 각각의 query를 나타내며 [s, e, k] 꼴이다
	각 query마다 s <= i <= e인 모든 i에 대해 k보다 크면서 가장 작은 arr[i]을 찾으시오
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer.reserve(_queries.size());

	const int MAX = 1'000'001;

	for (const vector<int> query : _queries)
	{

		int min = MAX;

		for (int i = query[0]; i <= query[1]; i++) 
		{

			min = _arr[i] > query[2] && _arr[i] < min ? _arr[i] : min;
		}

		if (min == MAX) answer.push_back(-1);
		else answer.push_back(min);
	}

	return answer;
}