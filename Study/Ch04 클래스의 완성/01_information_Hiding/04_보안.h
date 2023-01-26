/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 정보 은닉의 필요성
	Rectangle 클래스

	헤더파일 : 클래스 선언
*/

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "02_보안.h"

class Rectangle {

private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};

#endif
