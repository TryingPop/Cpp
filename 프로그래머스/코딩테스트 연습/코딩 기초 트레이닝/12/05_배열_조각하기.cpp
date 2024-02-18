#include <vector>

/*
날짜 : 2024. 2. 18
이름 : 배성훈
내용 : 배열 조각하기
	정수 배열 arr과 query가 주어진다
	query를 순회하면서 다음 작업을 반복
	짝수 인덱스에서는 arr에서 query[i]번 인덱스를 제외하고 배열의 query[i]번 인덱스 뒷부분을 잘라서 버린다
	홀수 인덱스에서는 arr에서 query[i]번 인덱스를 제외하고 배열의 query[i]번 인덱스 앞부분을 잘라서 버린다

	위 작업을 마친 후 남은 arr의 부분 배열을 return 하는 solution 함수 완성
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<int> _query)
{

	vector<int> answer = _arr;

	int s = 0, e = _arr.size() - 1;
	for (int i = 0; i < _query.size(); i++)
	{

		/*
		if (i & 1) answer.erase(answer.begin(), answer.begin() + _query[i]);
		else if (_query[i] < answer.size() - 1) answer.erase(answer.begin() + _query[i] + 1, answer.end());
		*/

		int calc = s + _query[i];
		if (i & 1) s = calc;
		else if (e > calc) e = calc;
	}

	for (int i = s; i <= e; i++)
	{

		answer.push_back(_arr[i]);
	}

	if (answer.empty()) answer.push_back(-1);
	return answer;
}