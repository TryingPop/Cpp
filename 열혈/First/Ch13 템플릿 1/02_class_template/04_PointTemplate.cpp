/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿
	코드파일 : Point 클래스의 정의
*/

#include <iostream>
#include "03_PointTemplate.h"
using namespace std;

template<typename T>
Point<T>::Point(T x, T y) 
	: xpos(x), ypos(y) { }

template<typename T>
void Point<T>::ShowPosition() const {

	cout << '[' << xpos << ", " << ypos << ']' << endl;
}