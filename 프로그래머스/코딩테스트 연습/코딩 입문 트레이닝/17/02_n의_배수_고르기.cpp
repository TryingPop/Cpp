#include <vector>

/*
날짜 : 2024. 3. 19
이름 : 배성훈
내용 : n의 배수 고르기
	정수 n과 정수 배열 numlist가
	매개변수로 주어질 때,

	numlist에서 n의 배수가 아닌 수들을
	제거한 배열을 return 하도록
	solution 함수를 구현
*/

using namespace std;

vector<int> solution(int _n, vector<int> _numlist) 
{

	vector<int> answer;
	answer.reserve(_numlist.size());

	for (const int i : _numlist)
	{

		if (i % _n) continue;
		answer.push_back(i);
	}

	return answer;
}