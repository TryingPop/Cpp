/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Struct
	Racing Car를 표현

	함수의 원형선언을 구조체 안에 두고, 함수의 정의를 구조체 밖으로 빼내는거
	대신에 함수가 어디에 정의되어 있는지에 대한 정보만 추가해주면 된다

	구조체 안에 함수가 정의되어져 있으면 함수를 인라인으로 처리해라는 내용이 내포되어져 있다
*/

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

struct Car {

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();		// 상태정보 출력
	void Accel();				// 엑셀, 속도증가
	void Break();				// 브레이크, 속도감소
};

void Car::ShowCarState() {

	cout << "소유자ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재속도 : " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {

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

void Car::Break() {

	if (curSpeed < CAR_CONST::BRK_STEP) {

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}


int main(void)
{

	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}