#include <string>
#include <vector>

/*
날짜 : 2024. 3. 1
이름 : 배성훈
내용 : 조건에 맞게 수열 변환하기 3
	정수 배열 arr와 자연수 k가 주어진다
	k가 홀수라면 arr의 모든 원소에 k를 곱하고
	k가 짝수라면 arr의 모든 원소에 k를 더한다

	이러한 변환을 마친 후의 arr를 return하는
	solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _k)
{

	vector<int> answer;
	answer.reserve(_arr.size());

	for (int i : _arr)
	{

		if (_k & 1) answer.push_back(i * _k);
		else answer.push_back(i + _k);
	}

	return answer;
}