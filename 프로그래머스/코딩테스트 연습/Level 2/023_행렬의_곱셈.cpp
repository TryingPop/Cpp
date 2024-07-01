/*
날짜 : 2024. 7. 1
이름 : 배성훈
내용 : 행렬의 곱셈
	2차원 행렬 arr1과 arr2를 입력받아,
	arr1과 arr2를 곱한 결과를 반환하는 함수
	solution 함수 구현

	arr1, arr2의 행과 열의 길이는 
	2이상 100 이하다

	arr1, arr2의 원소는 -10 이상 20이하인 자연수

	곱할 수 있는 배열만 주어진다


	parameter
	{ { 1, 4 }, { 3, 2 }, { 4, 1 } }, { { 3, 3 }, { 3, 3 } }


	return
	{ { 15, 15 }, { 15, 15 }, { 15, 15 } }
*/

#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> _arr1, vector<vector<int>> _arr2)
{

	vector<vector<int>> answer;
	answer.resize(_arr1.size());

	for (int i = 0; i < _arr1.size(); i++)
	{

		answer[i].reserve(_arr2[0].size());

		for (int j = 0; j < _arr2[0].size(); j++)
		{

			int val = 0;
			for (int mid = 0; mid < _arr1[0].size(); mid++)
			{

				val += _arr1[i][mid] * _arr2[mid][j];
			}

			answer[i].push_back(val);
		}
	}

	return answer;
}