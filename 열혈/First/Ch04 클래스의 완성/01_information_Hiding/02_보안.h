/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 정보 은닉의 필요성
	실수가 빠르게 발견되게 작성해보자
	Point 클래스

	헤더파일 : 클래스의 선언
*/

#ifndef __POINT_H_
#define __POINT_H_
class Point {

private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif