/*
날짜 : 2024. 6. 21
이름 : 배성훈
내용 : 구조체 안에 함수 삽입하기
	교재 p109 ~ 114

	C++ 에서는 구조체 안에 함수를 삽입하는것을 허용한다
	구조체 안에 삽입된 경우 구조체 내에 선언된 변수에 직접 접근이 가능하다

	그래서 함수를 실행시키면 구조체별로 함수가 있는거처럼 보일 수 있으나
	하나의 함수를 공유한 것이다

	하지만 작동에 대해서는 개별적으로 작동한다고 봐야한다
*/

#include <iostream>

using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{

	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{

		cout << "소유자 ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
	}

	void Accel()
	{

		if (fuelGauge <= 0) return;
		else fuelGauge -= FUEL_STEP;

		if (curSpeed + ACC_STEP >= MAX_SPD)
		{

			curSpeed = MAX_SPD;
			return;
		}

		curSpeed += ACC_STEP;
	}

	void Break() 
	{

		if (curSpeed < BRK_STEP)
		{

			curSpeed = 0;
			return;
		}

		curSpeed -= BRK_STEP;
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