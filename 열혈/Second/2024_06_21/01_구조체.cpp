/*
날짜 : 2024. 6. 21
이름 : 배성훈
내용 : 구조체의 등장배경
	교재 p106 ~ 109

	C언어로 프로그램을 구현한다면, 구조체의 정의는 항상 뒤를 따르기 마련이다
	연관 있는 데이터를 하나로 묶으면, 프로그램의 구현 및 관리가 용이하다

	소프트웨어를 단순히 표현하면 다음과 같다
	소프트웨어 = 데이터의 표현 + 데이터의 처리

	표현해야 하는 데이터는 항상 부류를 형성한다
	그래서 구조체는 연관ㄴ 있는 데이터를 묶을 수 있는 
	문법적 장치로 데이터의 표현에 매우 큰 도움을 준다

	C+언어에서는 struct를 매번 넣어줘야 했으나,
	C++에서는 별도의 typedef 선언 없이도 변수선언이 가능하다

	함수는 데이터의 처리를 담당하는 도구이니,
	데이터와 함께 부류를 형성하는 것은 매우 당연하다
	전역함수들은 구조체에 종속적임을 확실하게 명시하지 못한다
*/

#include <iostream>

using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car {

	char gamerID[ID_LEN];		// 소유자 ID
	int fuelGauge;				// 연료량
	int curSpeed;				// 현재 속도
};

void ShowCarState(const Car& car)
{

	cout << "소유자 ID: " << car.gamerID << endl;
	cout << "연료량: " << car.fuelGauge << endl;
	cout << "현재속도: " << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car& car)
{

	if (car.fuelGauge <= 0) return;
	else car.fuelGauge -= FUEL_STEP;

	if (car.curSpeed + ACC_STEP >= MAX_SPD) 
	{

		car.curSpeed = MAX_SPD;
		return;
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{

	if (car.curSpeed < BRK_STEP)
	{

		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main(void)
{

	Car run99 = { "run99", 100, 0 };
	Accel(run99);
	Accel(run99);
	// 소유자 ID: run99
	// 연료량: 96
	// 현재속도 : 20km / s
	ShowCarState(run99);
	Break(run99);

	// 소유자 ID : run99
	// 연료량 : 96
	// 현재속도 : 10km / s
	ShowCarState(run99);

	Car sped77 = { "sped77", 100, 0 };
	Accel(sped77);
	Break(sped77);

	// 소유자 ID : sped77
	// 연료량 : 98
	// 현재속도 : 0km / s
	ShowCarState(sped77);
	return 0;
}