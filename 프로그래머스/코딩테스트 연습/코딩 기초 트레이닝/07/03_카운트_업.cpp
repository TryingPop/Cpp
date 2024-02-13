#include <vector>

/*
날짜 : 2024. 2. 13
이름 : 배성훈
내용 : 카운트 업
	정수 start_num과 end_num이 주어질 때,
	start_num부터 end_num까지의 숫자를 차례로 담은 리스트를 return하도록
	solution 함수를 만드시오
*/

using namespace std;

vector<int> solution(int _start_num, int _end_num)
{

	vector<int> answer;
	answer.reserve(_end_num - _start_num + 1);

	for (int i = _start_num; i <= _end_num; i++)
	{

		answer.push_back(i);
	}

	return answer;
}