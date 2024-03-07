#include <vector>

/*
날짜 : 2024. 3. 7
이름 : 배성훈
내용 : 배열 두배 만들기
	정수 배열 numbers가 매개변수로 주어질 때,
	numbers의 각 원소에 두배한 원소를 가진 배열을
	return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _numbers) 
{

	vector<int> answer;
	answer.reserve(_numbers.size());

	for (int i : _numbers)
	{

		answer.push_back(i * 2);
	}

	return answer;
}