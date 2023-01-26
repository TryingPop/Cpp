/*
날짜 : 2023. 1. 26
이름 : 배성훈
내용 : 정보은닉의 필요성
	public으로 클래스 멤버변수를 선언했을 때 생기는 문제점
*/

#include <iostream>
using namespace std;

class Point {

public:
	int x;	// x 좌표의 범위는 0이상 100이하
	int y;	// y 좌표의 범위는 0이상 100이하
};

class Rectangle {

public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo() {

		cout << "좌 상단 : " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단 : " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl;
	}
};

int main(void) 
{

	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecInfo();
	return 0;
}