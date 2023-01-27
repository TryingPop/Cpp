/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 예시
	Exam Ch03 01 의 01 연습문제에 적용

	소스파일 : 클래스 정의
*/
#include <iostream>
#include "04_Point.h"
using namespace std;

Point::Point(const int& xpos, const int& ypos) {

	x = xpos;
	y = ypos;
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

bool Point::SetX(int xpos) {

	if (0 > xpos || xpos > 100) {

		cout << " 벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {

	if (0 > ypos || ypos > 100) {

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	y = ypos;
	return true;
}