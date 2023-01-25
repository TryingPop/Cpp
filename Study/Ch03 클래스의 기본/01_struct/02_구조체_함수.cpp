/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Struct
	Racing Car를 표현

	C++은 struct 안에 함수를 표현하는게 허용되어 함수 삽입

	정의한 매크로가 Car안에만 존재하는데
	이는 떨어진거처럼 보인다 Car 종속된거처럼 보이게 하기 위해
	enum을 이용해 Car안에 정의할 수 있다.
	혹은 이름공간안에 enum을 정의해도 된다
*/

#include <iostream>
using namespace std;


#define ID_LEN		20
#define MAX_SPD		200
#define	FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

// Car안에 함수는 하나의 함수를 공유한다
struct Car {

	char gamerID[ID_LEN];	// 소유자 ID
	int fuelGauge;			// 연료량
	int curSpeed;			// 현재 속도

	void ShowCarState() {

		cout << "소유자ID : " << gamerID << endl;
		cout << "연료량 : " << fuelGauge << "%" << endl;
		cout << "현재속도 : " << curSpeed << "km/s" << endl << endl;
	}

	void Accel() {

		if (fuelGauge <= 0) {

			return;
		}
		else {

			fuelGauge -= FUEL_STEP;
		}

		if (curSpeed + ACC_STEP >= MAX_SPD) {

			curSpeed = MAX_SPD;
			return;
		}

		curSpeed += ACC_STEP;
	}

	void Break() {

		if (curSpeed < BRK_STEP) {

			curSpeed = 0;
			return;
		}

		curSpeed -= BRK_STEP;
	}

};

// 01_struct와 같은 결과를 보인다
int main(void)
{

	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}