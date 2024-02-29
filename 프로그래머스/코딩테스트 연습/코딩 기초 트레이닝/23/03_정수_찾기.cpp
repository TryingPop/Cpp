#include <vector>

/*
날짜 : 2024. 2. 29
이름 : 배성훈
내용 : 정수 찾기
	정수 리스트 num_list와 찾으려는 정수 n이 주어질 때,
	num_list안에 n이 있으면 1을 없으면 0을
	return하는 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _num_list, int _n)
{

	int answer = 0;

	for (const int num : _num_list)
	{

		if (num != _n) continue;

		answer = 1;
		break;
	}

	return answer;
}