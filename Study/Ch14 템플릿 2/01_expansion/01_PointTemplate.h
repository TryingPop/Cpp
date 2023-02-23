/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 확장된 템플릿
	템플릿에 템플릿 클래스를 넣는 예제

	헤더파일 : Point 클래스의 선언과 정의
*/

#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_

#include<iostream>
using namespace std;

template<typename T>
class Point {

private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y)
	: xpos(x), ypos(y) { }

template <typename T>
void Point<T>::ShowPosition() const {

	cout << '[' << xpos << ", " << ypos << ']' << endl;
}
#endif
