/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : RacingCar class의 분할
	헤더파일 : 클래스의 선언
*/
#ifndef __CAR_H__	// ifndef 파일이 정의되어져 있지 않다면 #endif까지 무시 즉, 싱글톤과 비슷
#define __CAR_H__	

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

private :
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public :
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};
#endif