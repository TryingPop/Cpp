#include<vector>

/*
날짜 : 2024. 2. 19
이름 : 배성훈
내용 : n 번째 원소부터
	정수 리스트 num_list와 정수 n이 주어질 때,
	n번째 원소부터 마지막 원소까지의 모든 원소를 담은 리스트를
	return 하도록 solution 함수를 완성
*/
using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.assign(_num_list.begin() + _n - 1, _num_list.end());
	/*
	for (int i = n - 1; i < _num_list.size(); i++)
	{

		answer.push_back(_num_list[i]);
	}
	*/
	return answer;
}