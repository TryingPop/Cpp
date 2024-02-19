#include <vector>

/*
날짜 : 2024. 2. 19
이름 : 배성훈
내용 : n개 간격 원소들
	정수 리스트 num_list와 정수 n이 주어질 때,
	num_list의 첫 번째 원소부터 마지막 원소까지 n개 간격으로
	저장되어 있는 원소들을 차례로 담은 리스트를 return하도록 solution 함수를 완성
*/

using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	for (int i = 0; i < _num_list.size(); i += _n)
	{

		answer.push_back(_num_list[i]);
	}
	return answer;
}