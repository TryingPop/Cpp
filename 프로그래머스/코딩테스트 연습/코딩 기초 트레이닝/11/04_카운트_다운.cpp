#include <string>
#include <vector>

/*
날짜 : 2024. 2. 17
이름 : 배성훈
내용 : 카운트 다운
	정수 start_num와 end_num이 주어질 때,
	start_num에서 end_num까지 1씩 감소하는 수들을 차례로 담은
	리스트를 return하는 함수 구현
*/

using namespace std;

vector<int> solution(int _start, int _end_num)
{

	vector<int> answer;
	answer.reserve(_start - _end_num + 1);

	for (int i = _start; i >= _end_num; i--) 
	{

		answer.push_back(i);
	}

	return answer;
}