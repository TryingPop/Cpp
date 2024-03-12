#include <vector>

/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 짝수는 싫어요
	정수 n이 매개변수로 주어질 때,
	n 이하의 홀수를 오름차순으로 담은 배열을 
	return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;
	answer.reserve((_n + 1) / 2);

	for (int i = 1; i <= _n; i += 2) 
	{

		answer.push_back(i);
	}

	return answer;
}