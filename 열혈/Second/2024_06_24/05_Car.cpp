/*
날짜 : 2024 .6. 24
이름 : 배성훈
내용 : Car 클래스 정의
	교재 129 ~ 130
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "04_Car.h"

using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{

	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() 
{

	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
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

void Car::Break() 
{

	if (curSpeed < CAR_CONST::BRK_STEP)
	{

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}