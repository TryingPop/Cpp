#include <vector>

/*
날짜 : 2024. 2. 12
이름 : 배성훈
내용 : 수열과 구간 쿼리 3
	정수 배열 arr과 2차원 정수 배열 queries가 주어진다
	queries의 원소 query는 [i, j] 꼴이다
	각 query마다 arr[i]와 arr[j]를 바꾼다

	쿼리의 규칙에 따라 queries를 처리한 이후
	arr를 return 하는 solution 함수를 구현

	c++에는 자체적으로 swap함수가 있다
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer = _arr;

	// query에 &query로 표현해도 되고 그냥 query를 써도 된다
	// 어차피 클래스이므로 주소를 전달한다
	for (const vector<int> query : _queries)
	{

		// int temp = answer[query[0]];
		// answer[query[0]] = answer[query[1]];
		// answer[query[1]] = temp;
		swap(answer[query[0]], answer[query[1]]);
	}

	return answer;
}