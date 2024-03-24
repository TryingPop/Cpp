#include <vector>

/*
날짜 : 2024. 3. 24
이름 : 배성훈
내용 : 평행
	점 네 개의 좌표를 담은 이차원 배열
	dots가 다음과 같이 매개변수로 주어질때,
	{ { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 } }

	주어진 4 개의 점을 두 개씩 이었을 때,
	두 직선이 평행이 되는 경우가 있으면
	1을 없애면 0을 return 하는
	solution 함수 구현
*/

using namespace std;

int solution(vector<vector<int>> _dots)
{

	int answer = 0;

	// 평행인거 찾기
	for (int i = 1; i < 4; i++)
	{
		
		// 에드 훅으로 풀었다
		// 기울기를 비례식으로 썼다
		// 일반적인 방법은 CCW 알고리즘을 쓰면 될거 같다
		int diffX1 = _dots[0][0] - _dots[i][0];
		int diffY1 = _dots[0][1] - _dots[i][1];

		int diffX2 = 0;
		int diffY2 = 0;
		int mul = -1;

		for (int j = 1; j < 4; j++)
		{

			if (i == j) continue;
			diffX2 += mul * _dots[j][0];
			diffY2 += mul * _dots[j][1];
			mul *= -1;
		}

		int calc1 = diffX1 * diffY2;
		int calc2 = diffX2 * diffY1;
		
		if (calc1 != calc2) continue;
		answer = 1;
		break;
	}

	return answer;
}