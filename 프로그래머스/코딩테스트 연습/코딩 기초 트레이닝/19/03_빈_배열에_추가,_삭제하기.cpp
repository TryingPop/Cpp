#include <vector>

/*
날짜 : 2024. 2. 25
이름 : 배성훈
내용 : 빈 배열에 추가, 삭제하기
	빈 배열 X가 있다
	길이가 같은 정수 배열 arr과
	bool 배열 flag가 매개변수로 주어질 때,

	flag를 차례대로 순회하여
	flag[i]가 true면, X뒤에 arr[i]를 arr[i] * 2번 추가하고,
	flag[i]가 false면, X에서 마지막 arr[i]개의 원소를 제거한 뒤
	X를 return하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<bool> _flag)
{

	vector<int> answer;

	for (int i = 0; i < _flag.size(); i++)
	{

		if (_flag[i])
		{

			// 2번 추가
			for (int j = 0; j < _arr[i]; j++)
			{

				answer.push_back(_arr[i]);
				answer.push_back(_arr[i]);
			}
		}
		else
		{

			// 제거
			for (int j = 0; j < _arr[i]; j++) 
			{

				answer.pop_back();
			}
		}
	}
	return answer;
}