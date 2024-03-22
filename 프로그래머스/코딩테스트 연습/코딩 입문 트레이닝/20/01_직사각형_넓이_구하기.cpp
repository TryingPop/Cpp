#include <vector>

/*
날짜 : 2024. 3. 22
이름 : 배성훈
내용 : 직사각형 넓이 구하기
	2차원 좌표 평면에 변이
	축과 평행한 직사각형이 있다

	직사각형 네 꼭짓점의 좌표
	{ { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 } }
	가 담겨있는 배열 dots가 매개변수로 주어질 때,
	직사각형의 넓이를 return 하도록 solution 함수 구현

	각 좌표는 -256을 넘지 않고
	잘못 입력되는 경우는 없다
*/

using namespace std;

int solution(vector<vector<int>> _dots)
{

	int answer = 0;

	int w = 0;
	int h = 0;

	for (int i = 1; i < 4; i++)
	{

		if (w == 0) w = _dots[0][0] - _dots[i][0];
		if (h == 0) h = _dots[0][1] - _dots[i][1];
	}

	w = w < 0 ? -w : w;
	h = h < 0 ? -h : h;
	answer = w * h;
	return answer;
}