#include <vector>

/*
날짜 : 2024. 2. 19
이름 : 배성훈
내용 : n 번째 원소까지
	정수 리스트 num_list와 정수 n이 주어질 때, 
	num_list의 첫 번째 원소부터 n번째 원소까지의
	모든 원소를 담은 리스트를 return 하는 solution 함수 구현
*/
using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.assign(_num_list.begin(), _num_list.begin() + _n);
	return answer;
}