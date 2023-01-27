/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 예시
	Exam Ch03 01 의 01 연습문제에 적용

	헤더파일 : 클래스 선언
*/

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "04_Point.h"

class Rectangle {

private:
	Point upLeft;
	Point lowRight;

public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};
#endif