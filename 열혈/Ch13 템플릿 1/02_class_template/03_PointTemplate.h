/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿
	앞에서 정의한 템플릿 클래스의 분할

	헤더파일 : Point 클래스의 선언
*/

#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template <typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

#endif