/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : CarInline
	교재 p133 ~ 134
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "07_CarInline.h"

using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{

	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::Accel() 
{

	if (fuelGauge <= 0) return;
	else fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{

		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}