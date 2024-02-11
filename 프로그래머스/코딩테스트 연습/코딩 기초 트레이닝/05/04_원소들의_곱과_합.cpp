#include <vector>

/*
날짜 : 2024. 2. 11
이름 : 배성훈
내용 : 원소들의 곱과 합
	정수가 담긴 리스트가 주어질 때, 모든 원소들의 합의 제곱이 큰지 혹은 곱이 큰지 비교해서
	곱이 크면 0을 합의 제곱이 크면 1을 출력하는 함수 만들기

	같은 경우는 안주어진다
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int calc1 = 1;		// 곱 연산
	int	calc2 = 0;		// 합 연산

	for (const int c : _num_list) 
	{

		calc1 *= c;
		calc2 += c;
	}

	calc2 *= calc2;
	answer = calc1 < calc2;
	return answer;
}