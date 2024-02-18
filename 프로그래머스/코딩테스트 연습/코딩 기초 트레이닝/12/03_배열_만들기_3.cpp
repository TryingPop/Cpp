#include<vector>

/*
날짜 : 2024. 2. 18
이름 : 배성훈
내용 : 배열 만들기 3
	정수 배열 arr과 2개의 구간이 담긴 배열 intervals가 주어진다
	intervals는 항상 { { a1, b1 }, { a2, b2 } } 의 꼴로 주어지며 각 구간은 폐구간
	이때 배열 arr의 첫 번째 구간에 해당하는 배열과 두 번째 구간에 해당하는 배열을 앞뒤로 붙여
	새로운 배열을 만들어 return 하는 solution 함수 완성하기
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _intervals)
{

	vector<int> answer;
	for (const vector<int> interval : _intervals)
	{

		for (int i = interval[0]; i <= interval[1]; i++) 
		{

			answer.push_back(_arr[i]);
		}
	}

	return answer;
}