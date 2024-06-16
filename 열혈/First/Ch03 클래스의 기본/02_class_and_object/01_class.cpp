/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : class를 이용해 RacingCar 표현
	앞에 사용한 RacingCar를 class를 이용해 표현해보자

	class 내부의 값은 별다른 표현이 없으면 다른 영역에서 수정하지 못한다
	c++에서 구조체는 class의 일부
*/

#include <iostream>
#include <cstring>
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

	// 클래스 내(클래스 내에서 정의된 함수)에서만 접근 허용
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	// 어디서든 접근 허용
public:
	// void InitMembers(char* ID, int fuel);	// 일반 문자열을 넣을 경우 const char []에서 char*로 변환할 수 없다는 에러 뜬다
	// 현재는 변환하지 않기에 const를 붙여준다 이경우 잘 실행된다
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel) {

	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

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

int main(void) {

	Car run99;

	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}