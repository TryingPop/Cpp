#include <vector>
#include <algorithm>
#define DIFF 5

/*
날짜 : 2024. 2. 27
이름 : 배성훈
내용 : 뒤에서 5등 위로
	정수로 이루어진 리스트 num_list가 주어진다
	num_list에서 가장 작은 5개의 수를 제외한 수들을
	오름차순으로 담은 리스트를 return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	answer.reserve(_num_list.size() - DIFF);

	vector<int> temp = _num_list;
	sort(temp.begin(), temp.end());

	answer.assign(temp.begin() + 5, temp.end());
	return answer;
}