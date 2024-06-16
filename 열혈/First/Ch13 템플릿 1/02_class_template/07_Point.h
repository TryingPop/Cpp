/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 배열 클래스의 템플릿화
	헤더파일 : Point 클래스의 선언
*/

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0);
	friend ostream& operator<<(ostream& os, const Point& pos);
};

#endif