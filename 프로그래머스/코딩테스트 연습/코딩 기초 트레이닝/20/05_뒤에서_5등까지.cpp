#include <vector>
#include <algorithm>
#define LEN 5

/*
날짜 : 2024. 2. 26
이름 : 배성훈
내용 : 뒤에서 5등까지
	정수로 이루어진 리스트 num_list가 주어진다
	num_list에서 가장 작은 5개의 수를 오름차순으로 담은
	리스트를 return 하도록 solution 함수를 구현
*/
using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	answer.reserve(LEN);

	vector<int> sortArr = _num_list;

	// 정렬
	sort(sortArr.begin(), sortArr.end());

	// 가장 작은 5개 할당
	answer.assign(sortArr.begin(), sortArr.begin() + LEN);

	return answer;
}