#include <vector>

/*
날짜 : 2024. 3. 2
이름 : 배성훈
내용 : 정수를 나선형으로 배치하기
	양의 정수 n이 매개변수로 주어진다

	n * n 배열에 1부터 n^2까지 정수를
	인덱스 [0][0]부터 시계방향
	나선형으로 배치한 이차원 배열을 
	return하는 solution 함수 구현
*/

using namespace std;

vector<vector<int>> solution(int _n)
{

	// n * n 크기에 0으로 초기화
	vector<vector<int>> answer(_n, vector<int>(_n, 0));

	// 방향 우하좌상
	vector<pair<int, int>> dir{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	int cur = 1;
	int curDir = 0;
	int curX = -1, curY = 0;

	// 나선 그리기
	while (cur <= _n * _n) 
	{

		int nextX = curX + dir[curDir].first;
		int nextY = curY + dir[curDir].second;

		if (nextX < 0 || nextX >= _n || nextY < 0 || nextY >= _n 
			|| answer[nextY][nextX]) 
		{

			// 앞에 숫자가 있거나 끝지점인 경우 방향 변경
			curDir = curDir == 3 ? 0 : curDir + 1;
			continue;
		}

		answer[nextY][nextX] = cur++;
		curX = nextX;
		curY = nextY;
	}

	return answer;
}