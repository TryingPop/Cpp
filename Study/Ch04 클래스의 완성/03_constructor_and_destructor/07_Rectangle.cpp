/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 예시
	Exam Ch03 01 의 01 연습문제에 적용

	소스파일 : 클래스 정의
*/

#include <iostream>
#include "06_Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2) : upLeft(x1, y1), lowRight(x2, y2) {

	// empty
}

void Rectangle::ShowRecInfo() const {

	cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}