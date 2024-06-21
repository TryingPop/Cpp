/*
날짜 : 2024. 6. 21
이름 : 배성훈
내용 : 구조체 안에 enum 상수의 선언
	교재 p115 ~

	앞의 예제에서 매크로 상수들은 구조체 Car에만 의미가 있는 상수들이다
	이들 상수도 구조체 내에 포함시키는 것이 좋을 수 있다 (상황마다 약간씩 다르다)

	enum의 선언을 구조체 내부에 삽입하는 것이 붇담스럽다면,
	이름공간을 이용하면, 구조체 사이에서만 사용하는 상수들을 선언할 때 도움이되며
	가독성도 좋아질 수 있다

	구조체 내에 함수를 정의했을 뿐인데,
	구조체가 너무 커져버린 느낌이 든다
*/

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

struct Car 
{

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() 
	{

		cout << "소유자 ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
	}

	void Accel() {

		if (fuelGauge <= 0) return;
		else fuelGauge -= CAR_CONST::FUEL_STEP;

		if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
		{

			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}

		curSpeed += CAR_CONST::ACC_STEP;
	}

	void Break() 
	{

		if (curSpeed < CAR_CONST::BRK_STEP)
		{

			curSpeed = 0;
			return;
		}

		curSpeed -= CAR_CONST::BRK_STEP;
	}
};

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