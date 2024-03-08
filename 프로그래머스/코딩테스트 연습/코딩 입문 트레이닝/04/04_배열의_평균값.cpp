#include <vector>

/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 배열의 평균값
	정수 배열 numbers가 매개변수로 주어진다
	numbers의 원소의 평균값을 return 하도록
	solution 함수를 구현

	정답의 소수부분은 .0 또는 .5이다
*/

using namespace std;

double solution(vector<int> _numbers)
{

	double answer = 0;

	for (int i : _numbers)
	{

		answer += i;
	}

	answer /= _numbers.size();
	return answer;
}