#include <vector>

/*
날짜 : 2024. 2. 26
이름 : 배성훈
내용 : 배열 비교하기
	두 배열의 길이가 다르다면, 배열의 길이가 긴 쪽이 더 크다
	두 배열의 길이가 같다면, 모든 원소의 합을 더하여 더 큰쪽이 크고
	같다면 같다

	arr1, arr2가 주어질 때, arr1이 크다면 1, arr2가 크면 2, 같을 경우 0을
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(vector<int> _arr1, vector<int> _arr2)
{

	int answer;

	if (_arr1.size() != _arr2.size())
	{

		answer = _arr1.size() > _arr2.size() ? 1 : -1;
	}
	else 
	{

		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < _arr1.size(); i++)
		{

			sum1 += _arr1[i];
			sum2 += _arr2[i];
		}

		if (sum1 > sum2) answer = 1;
		else if (sum1 < sum2) answer = -1;
		else answer = 0;
	}
	return answer;
}