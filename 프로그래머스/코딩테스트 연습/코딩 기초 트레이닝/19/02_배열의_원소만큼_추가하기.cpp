#include <vector>

/*
날짜 : 2024. 2. 25
이름 : 배성훈
내용 : 배열의 원소만큼 추가하기
	아무 원소도 들어있지 않은 빈 배열 X가 있다
	양의 정수로 이루어진 배열 arr이 주어질 때,
	arr의 앞에서부터 차례대로 원소를 보면서
	원소가 a라면 X의 맨 뒤에 a를 a번만큼 추가하는
	일을 반복한 뒤의 배열 X를 return하는
	solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;

	for (const int i : _arr)
	{

		for (int j = 0; j < i; j++)
		{

			answer.push_back(i);
		}
	}
	return answer;
}