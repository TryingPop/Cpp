#include <vector>

/*
날짜 : 2024. 2. 17
이름 : 배성훈
내용 : 배열 만들기 1
	정수 n과 k가 주어졌을 때, 1 이상 n이하의 정수 중에서 k의 배수를
	오름차순으로 저장한 배열을 return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(int _n, int _k)
{

	vector<int> answer;
	
	for (int i = _k; i <= _n; i += _k)
	{

		answer.push_back(i);
	}
	
	return answer;
}