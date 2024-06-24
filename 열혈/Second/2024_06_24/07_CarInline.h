/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : CarInline 헤더파일
	교재 p131 ~ 133

	컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 하므로
	인라인 함수는 클래스의 선언과 동일한 파일에 저장되어서
	컴파일러가 동시에 참조할 수 있게 해야한다
*/

#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>

using namespace std;

namespace CAR_CONST
{

	enum
	{

		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car 
{

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

inline void Car::ShowCarState()
{

	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
}

inline void Car::Break() 
{

	if (curSpeed < CAR_CONST::BRK_STEP)
	{

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

#endif