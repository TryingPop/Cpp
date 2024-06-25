/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : Point 소스파일
	교재 p154 ~ 155

	멤버변수를 private로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서,
	안전한 형태로 멤버변수의 접근을 유도하는 것이 바로 정보은닉이며
	이는 좋은 클래스가 되기 위한 기본조건이 된다

	아래 예제에서
	GetX, SetX, GetY, SetY는 엑세스 함수(accesss function)라 하는데,
	이들은 멤버 변수를 private로 선언하면서
	클래스 외부에서 멤버변수 접근을 목적으로 정의되는 함수들이다

	클래스를 정의할 때 호출될 함수들 위주로 멤버함수를 구성하는 것은 분명 맞다
	그러나 클래스의 정의과정에서 당장은 필요하지 않지만,
	필요할 수 있다고 판단되는 함수들도 더불어 멤버에 포함시키는 경우도 많다
	대표적인 예가 엑세스 함수들이다
	호출되지 않지만 삽입된 함수가 있다면, 이러한 맥락에서 이해하면 좋다
*/

#include <iostream>
#include "02_Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{

	if (xpos < 0 || ypos < 0) 
	{

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const	// const 함수
{

	return x;
}

int Point::GetY() const	// const 함수
{

	return y;
}

bool Point::SetX(int xpos)
{

	if (0 > xpos || xpos > 100)
	{

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{

	if (0 > ypos || ypos > 100)
	{

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	y = ypos;
	return true;
}