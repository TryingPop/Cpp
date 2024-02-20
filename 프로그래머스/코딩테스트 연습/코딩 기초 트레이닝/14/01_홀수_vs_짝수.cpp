#include <vector>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 홀수 vs 짝수
	정수 리스트 num_list가 주어진다
	가장 첫 번째 원소를 1번 원소라고 할 때,
	홀수 번째 원소들의 합과 짝수 번째 원소들의 합 중 큰 값을 return 하도록 solution 함수를 구현
	두 값이 같은 경우 그 값을 return
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int odd = 0, even = 0;
	for (int i = 0; i < _num_list.size(); i++)
	{

		if (i & 1) even += _num_list[i];
		else odd += _num_list[i];
	}

	answer = even < odd ? odd : even;

	return answer;
}