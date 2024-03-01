#include <vector>

/*
날짜 : 2024. 3. 1
이름 : 배성훈
내용 : 특별한 이차원 배열 1
	정수 n이 매개변수로 주어진다

	n * n 크기의 이차원 배열 arr을
		arr[i][j] (0 <= i, j < n)
		i == j, arr[i][j] = 1
		i != j, arr[i][j] = 0

	return 하는 solution 함수 구현
*/
using namespace std;

vector<vector<int>> solution(int _n)
{

#if first
	vector<vector<int>> answer;
	vector<int> temp(_n, 0);
	
	for (int i = 0; i < _n; i++)
	{

		temp[i] = 1;
		answer.push_back(temp);
		temp[i] = 0;
	}

	return answer;
#elif second
	vector<vector<int>> answer(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{

		answer[i][i] = 1;
	}

	return answer;
#endif
}