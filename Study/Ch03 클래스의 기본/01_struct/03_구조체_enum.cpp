/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Struct
	Racing Car를 표현

	이름 공간을 이용해 매크로 표현

	보통은 함수의 기능만 파악을 하지 함수의 세부구현까지는 신경 안쓴다
	그래서 구조체안에 함수의 정의가 길다면 선언만 하고 외부에서 정의하는 방법이있다
*/
#include <iostream>
using namespace std;

// 매크로 부분을 다음과 같이 대체
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

	char gameID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {

		cout << "소유자ID : " << gameID << endl;
		cout << "연료량 : " << fuelGauge << "%" << endl;
		cout << "현재속도 : " << curSpeed << "km/s" << endl << endl; 
	}

	void Accel() {

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

	void Break() {

		if (curSpeed < CAR_CONST::BRK_STEP) {

			curSpeed = 0;
			return;
		}

		curSpeed -= CAR_CONST::BRK_STEP;
	}
};

// 앞과 같은 결과를 보인다
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