/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : Point 클래스
	교재 p153 ~ 154

	01의 point 클래스를 수정했다
	멤버변수 x와 y를 private로 선언해서 임의로 값이 저장되는 것을 막았다
	x와 y를 은닉한 상황이다

	대신에 값의 저장 및 참조를 위한 함수를 추가로 정의했다
	이 함수 내에서 멤버변수에 저장되는 값을 제한할 수 있다
*/

#ifndef __POINT_H__
#define __POINT_H__

class Point
{

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