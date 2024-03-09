#include <vector>

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 짝수 홀수 개수
	정수가 담긴 리스트 num_list가 주어질 때,
	num_list의 원소 중 짝수와 홀수의 개수를 담은 배열을
	return하는 solution 함수 구현

	여기서 num_list의 원소는 음이아닌 정수
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	// 크기 2, 0으로 초기값 할당
	vector<int> answer(2, 0);

	for (const int n : _num_list)
	{

		if (n & 1) answer[1]++;
		else answer[0]++;
	}

	return answer;
}