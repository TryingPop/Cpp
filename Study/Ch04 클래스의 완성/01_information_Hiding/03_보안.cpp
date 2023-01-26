/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 정보 은닉의 필요성
	Point 클래스

	소스파일 : 함수의 정의

	멤버변수를 private으로 선언하고, 
	해당 변수에 접근하는 함수를 별도로 정의해서,
	안전한 형태로 멤버변수의 접근을 유도하는 것이 바로 '정보은닉'이며,
	이는 좋은 클래스가 되기 위한 기본조건이 된다.
*/

#include <iostream>
#include "02_보안.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos) {

	if (xpos < 0 || ypos < 0 || xpos > 100 || ypos > 100) {

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const {	// const 함수
							// 멤버변수에 저장된 값을 변경하지 않겠다는 의미
							// const함수는 const 함수만 호출 가능
							// 참조자 역시 마찬가지

	return x;
}

int Point::GetY() const {

	return y;
}

bool Point::SetX(int xpos) {

	if (0 > xpos || xpos > 100) {

		cout << "벗어난 범위의 값 전달" << endl;
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