/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 정보 은닉의 필요성
	Rectangle 클래스

	헤더파일 : 클래스 정의
*/

#include <iostream>
#include "04_보안.h"
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {

	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {

		cout << "잘못된 위치정보 전달" << endl;
		return false;
	}

	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const {

	cout << "좌 상단 : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단 : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}