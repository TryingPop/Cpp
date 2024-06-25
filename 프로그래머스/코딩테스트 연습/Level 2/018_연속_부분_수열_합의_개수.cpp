/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 연속 부분 수열 합의 개수
	원형 수열의 원소 elements가 순서대로 주어질 때,
	원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를
	return 하는 solution 함수 구현

	parameter
	{ 7, 9, 1, 1, 4 }


	return
	18


	sol
	길이 1은 { 1, 4, 7, 9 } 4가지가 존재
	길이 2는 { 2, 5, 10, 11, 16 } 5가지가 존재
	길이 3은 { 6, 11, 12, 17, 20 } 5가지가 존재
	길이 4는 { 13, 15, 18, 21 } 4가지가 존재
	길이 5는 { 22 } 1가지가 존재

	중복을 { 11 } 1개를 제외하면 전체는 18개이다
*/

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> _elements)
{

	int answer = 0;

	int len = _elements.size();
	_elements.resize(len * 2);

	for (int i = 0; i < len; i++)
	{

		_elements[i + len] = _elements[i];
	}

	unordered_map<int, bool> use;

	for (int i = 0; i < len; i++)
	{

		int cur = 0;
		for (int j = 0; j < len; j++)
		{

			cur += _elements[i + j];
			if (use[cur]) continue;

			use[cur] = true;
			answer++;
		}
	}

	return answer;
}