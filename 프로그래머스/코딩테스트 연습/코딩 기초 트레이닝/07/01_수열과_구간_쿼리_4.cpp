#include <vector>

/*
날짜 : 2024. 2. 13
이름 : 배성훈
내용 : 수열과 구간 쿼리 4
	정수 배열 arr과 2차원 정수 배열 queries가 주어진다
	queries의 원소는 각각 하나의 query를 나타내며
	{ s, e, k }꼴이다

	각 query마다 순서대로 s <= i <= e인 모든 i에 대해 i가 k의 배수이면
	arr[i]에 1을 더한다

	위 규칙에 따라 queries를 처리한 이후의 arr를 반환하는 soltuion 함수 만들기
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer.reserve(_arr.size());
	answer = _arr;

	for (vector<int> query : _queries)
	{

		for (int i = query[0]; i <= query[1]; i++)
		{

			if (i % query[2] == 0) 
			{

				answer[i] += 1;
			}
		}
	}

	return answer;
}