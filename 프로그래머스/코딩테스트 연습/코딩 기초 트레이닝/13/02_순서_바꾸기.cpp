#include <vector>

/*
날짜 : 2024. 2 19
이름 : 배성훈
내용 : 순서 바꾸기
	정수 리스트 num_list와 정수 n이 주어질 때,
	num_list를 n번째 원소 이후의 원소들과 n번째 까지의 원소들로 나눠
	n번째 원소 이후의 원소들을 n번째까지의 원소들 앞에 붙인 
	리스트를 return 하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.reserve(_num_list.size());

	for (int i = _n; i < _num_list.size(); i++)
	{

		answer.push_back(_num_list[i]);
	}

	for (int i = 0; i < _n; i++)
	{

		answer.push_back(_num_list[i]);
	}

	// answer.assign(_num_list.begin() + _n, _num_list.end());
	// answer.insert(answer.end(), _num_list.begin(), _num_list.begin() + _n);
	return answer;
}