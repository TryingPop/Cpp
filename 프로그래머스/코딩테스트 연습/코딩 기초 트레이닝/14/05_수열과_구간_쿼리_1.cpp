#include <vector>

/*
날짜 : 2024. 2. 20
이름 : 배성훈
내용 : 수열과 구간 쿼리 1
	정수 배열 arr과 2차원 정수 배열 queries가 주어진다
	queries의 원소는 각각 하나의 query를 나타내며,
	{ s, e } 꼴입니다

	각 query마다 순서대로 s <= i <= e인 모든 i에 대해 arr[i]에 1을 더한다
	위 규칙에 따라 queries를 처리한 이후의 arr를 return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;

	answer = _arr;

	for (const vector<int> query : _queries)
	{

		for (int i = query[0]; i <= query[1]; i++)
		{

			answer[i] += 1;
		}
	}

	return answer;
}