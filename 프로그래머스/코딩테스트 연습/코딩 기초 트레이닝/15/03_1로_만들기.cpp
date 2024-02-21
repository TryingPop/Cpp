#include <vector>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 1로 만들기
	정수가 있을 때, 짝수라면 반으로 나누고
	홀수라면 1을 빼서 반으로 나누면
	마지막에 1이 된다
	정수들이 담긴 리스트 num_list가 주어질 때,
	num_list의 모든 원소를 1로 만들기 위해서 
	나누기 연산의 횟수를 return하도록 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer = 0;

	for (int i : _num_list)
	{

		while (i != 1)
		{

			i /= 2;
			answer++;
		}
	}

	return answer;
}