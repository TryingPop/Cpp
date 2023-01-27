/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 예시
	Exam Ch03 01 의 01 연습문제에 적용

	헤더파일 : 클래스 선언
*/

#ifndef __POINT_H_
#define __POINT_H_

class Point {

private:
	int x;
	int y;

public:
	Point(const int& xpos, const int& ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif

