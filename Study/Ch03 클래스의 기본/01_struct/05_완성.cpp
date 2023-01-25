/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Struct
	Racing Car를 표현

	완벽하게 구현한 모습
*/

#include <iostream>
using namespace std;

namespace CAR_CONST{

	enum {

		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car {

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();
};

inline void Car::ShowCarState() {

	cout << "소유자ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재속도 : " << curSpeed << "km/s" << endl; << endl;
}

inline void Car::Accel() {

	if (fuelGauge <= 0) {

		return;
	}
	else {

		fuelGauge -= CAR_CONST::FUEL_STEP;
	}


	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {

		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

inline void Car::Break() {

	if (curSpeed < CAR_CONST::BRK_STEP) {

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}