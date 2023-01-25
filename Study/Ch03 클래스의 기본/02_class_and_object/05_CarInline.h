/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Inline을 이용해 RacingCar class의 분할
	헤더파일 : 클래스의 선언과 inline함수 정의

	inline 함수는 컴파일러가 동시에 참조할 수 있게 해야한다
	컴파일 과정에서 하나의 실행 파일을 만들 때,
	해당 cpp 파일만 참조할 뿐 다른 cpp 파일을 참조하지 않는다
*/
#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>
using namespace std;

namespace CAR_CONST {

	enum {

		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car {

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

inline void Car::ShowCarState() {

	cout << "소유자ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재속도 : " << curSpeed << "km/s" << endl << endl;
};

inline void Car::Break() {

	if (curSpeed < CAR_CONST::BRK_STEP) {

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

#endif
