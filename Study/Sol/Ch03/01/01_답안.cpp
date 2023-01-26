/*
날짜 : 2023. 1. 26
이름 : 배성훈
내용 : 교재 114p 문제1
	2차원 평면상에서 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.
	struct Point {
		int xpos;
		int ypos;
	};
	위의 구조체를 기반으로 다음의 함수를 정의하고자 한다(자세한 기능은 실행의 예를 통해서 확인하도록 한다).
	void MovePos(int x, int y);			// 점의 좌표이동
	void AddPoint(const Point &pos);	// 점의 좌표증가
	void ShowPosition();				// 현재 x, y 좌표정보 출력
	단, 위의 함수들을 구조체 안에 정의를 해서 다음의 형태로 main 함수를 구성할 수 있어야한다.
	int main(void)
	{
		Point pos1 = { 12, 4 };
		Point pos2 = { 20, 30 };
		pos1.MovePos(-7, 10);
		pos1.ShowPosition();		// [5, 14] 출력

		pos1.AddPoint(pos2);
		pos1.ShowPosition();		// [25, 44] 출력
		return 0;
	}
*/

#include <iostream>
using namespace std;

struct Point
{

	int xpos;
	int ypos;

	void MovePos(int x, int y) {

		xpos += x;
		ypos += y;
	}

	void AddPoint(const Point& pos) {

		xpos += pos.xpos;
		ypos += pos.ypos;
	}

	void ShowPosition() {

		cout << "[" << xpos << " ," << ypos << "]" << endl;
	}
};

int main(void) 
{

	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}