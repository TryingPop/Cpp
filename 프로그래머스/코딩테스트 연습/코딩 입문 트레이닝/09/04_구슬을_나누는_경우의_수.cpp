#include <vector>

/*
날짜 : 2024. 3. 11
이름 : 배성훈
내용 : 구슬을 나누는 경우의 수
	갖고 있는 구슬의 개수 balls와 나눠줄 구슬의 개수 share가
	매개변수로 주어질 때,
	balls개의 구슬 중 share개의 구슬을 고르는 가능한 모든 경우의 수를
	return 하는 solution 함수 구현
*/

using namespace std;

int combi(int _n, int _r)
{

	if (_n < 2 || _r <= 0 || _r >= _n) return 1;

	int answer;
	answer = combi(_n - 1, _r - 1) + combi(_n - 1, _r);
	return answer;
}

int solution(int _balls, int _share)
{

	int answer;
	
	// 파스칼 삼각형을 만들어 구현
	// 1회용으로 하기에는 규모가 너무 크다
	// 1회를 묻는 경우 위와 같이 재귀함수 구현하는게 더 싸다
	vector<vector<int>> pascal = vector<vector<int>>(31);

	pascal[0] = vector<int>(1, 1);
	pascal[1] = vector<int>(2, 1);

	for (int i = 2; i <= 30; i++)
	{

		pascal[i] = vector<int>(i + 1, 1);
		for (int j = 1; j < i; j++)
		{

			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	answer = pascal[_balls][_share];
	return answer;
}