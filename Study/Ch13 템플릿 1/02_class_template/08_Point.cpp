/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 배열 클래스의 템플릿화
	코드파일 : Point 클래스의 정의
*/

#include <iostream>
#include "07_Point.h"

using namespace std;

Point::Point(int x, int y)
	: xpos(x), ypos(y) { }

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}