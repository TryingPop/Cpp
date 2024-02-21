#include <vector>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 길이에 따른 연산
	정수가 담긴 리스트 num_list가 주어질 때,
	리스트의 길이가 11 이상이면
	리스트에 있는 모든 원소의 합을
	10 이하이면 모든 원소의 곱을
	return 하도록 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;
	if (_num_list.size() > 10)
	{

		answer = 0;
		for (const int i : _num_list)
		{

			answer += i;
		}
	}
	else 
	{

		answer = 1;
		for (const int i : _num_list)
		{

			answer *= i;
		}
	}

	return answer;
}