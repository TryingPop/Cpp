#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 배열 뒤집기
	정수가 들어 있는 배열 num_list가 매개변수로 주어질 때,
	num_list의 원소의 순서를 거꾸로 뒤집은 배열을
	return하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _num_list) 
{

	vector<int> answer = _num_list;

	// 뒤집기
	reverse(answer.begin(), answer.end());
	return answer;
}