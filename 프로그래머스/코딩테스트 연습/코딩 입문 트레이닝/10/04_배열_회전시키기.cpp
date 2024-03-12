#include <vector>
#include <string>
#include <algorithm>


/*
날짜 : 2024. 3. 12
이름 : 배성훈
내용 : 배열 회전시키기
	정수가 담긴 배열 numbers와 문자열 direction이
	매개변수로 주어진다

	배열 numbers 원소를 direction 반향으로 한칸씩
	회전시킨 배열을 return 하는 solution 함수를 구현

	direction은 left와 right만 주어진다
*/

using namespace std;

vector<int> solution(vector<int> _numbers, string _direction) 
{

	// vector<int> answer;
	// answer.reserve(_numbers.size());
	vector<int> answer = _numbers;

	if (_direction == "left")
	{

		// 원소들을 swap하면서 회전한다
		// 하나씩 swap하기에 매우 비효율적이다
		// 왼쪽 1칸 이동
		// begin() + a : 왼쪽으로 a칸 이동
		rotate(answer.begin(), answer.begin() + 1, answer.end());

		/*
		for (int i = 1; i < _numbers.size(); i++)
		{

			answer.push_back(_numbers[i]);
		}
		answer.push_back(_numbers[0]);
		*/

	}
	else 
	{

		// 오른쪽 1칸 이동
		// end() - a : 오른쪽 a칸 이동
		rotate(answer.begin(), answer.end() - 1, answer.end());
		/*
		answer.push_back(_numbers.back());
		for (int i = 0; i < _numbers.size() - 1; i++)
		{

			answer.push_back(_numbers[i]);
		}
		*/
	}

	return answer;
}