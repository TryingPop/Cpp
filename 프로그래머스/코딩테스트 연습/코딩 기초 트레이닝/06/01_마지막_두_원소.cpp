#include <vector>

/*
날짜 : 2024. 2. 12
이름 : 배성훈
내용 : 마지막 두 원소
	정수 리스트 num_lis가 주어질 때, 마지막 원소가 그전 원소보다 크면
	마지막 원소에서 그전 원소를 뺀 값을
	마지막 원소가 그전 원소보다 크지 않다면 마지막 원소를 두 배한 값을 추가하여
	return하는 함수 만들기
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	int size = _num_list.size();
	answer.reserve(4 * (size + 1));

	for (const auto n : _num_list)
	{

		answer.push_back(n);
	}

	// 비교해서 마지막에 원소 넣기
	if (answer[size - 2] < answer[size - 1]) answer.push_back(answer[size - 1] - answer[size - 2]);
	else answer.push_back(answer[size - 1] * 2);
	return answer;
}