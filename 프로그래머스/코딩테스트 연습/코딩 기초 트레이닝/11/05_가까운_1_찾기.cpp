#include <vector>

/*
날짜 : 2024. 2. 17
이름 : 배성훈
내용 : 가까운 1 찾기
	정수 배열 arr이 주어진다
	이때 arr의 원소는 1 또는 0
	정수 idx가 주어졌을 때, idx이상인 인덱스에 대해 배열의 값이 1인 
	가장 작은 인덱스를 찾아서 반환하는 solution 함수 구현

	만약 없다면 -1 반환
*/

using namespace std;

int solution(vector<int> _arr, int _idx)
{

	int answer = -1;

	for (int i = _idx; i < _arr.size(); i++)
	{

		if (_arr[i] == 1) 
		{ 
			
			answer = i; 
			break;
		}
	}

	return answer;
}