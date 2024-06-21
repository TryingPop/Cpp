/*
날짜 : 2024. 6. 21
이름 : 배성훈
내용 : 함수를 외부에 정의
	교재 p118 ~ 121

	함수가 포함되어 있는 C++의 구조체를 보는 순간
	선언되어 있는 변수정보, 정의되어 있는 함수정보
	가 쉽게 눈에 들어와야 코드의 분석이 용이하다

	프로그램을 분석할 때, 흐름 및 골격 위주로 분석하는 경우가 많다
	그리고 이러한 경우에는 함수의 기능만 파악을 하지
	함수의 세부구현까지는 신경을 쓰지 않는다

	따라서 정의되어 있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 작성하는 것이 좋다
	따라서 구조체 내에 정의되어 있는 함수의 수가 많거나 그 길이가 길다면,
	구조체 밖으로 함수를 빼낼 필요가 있다

	즉, 함수의 원형선언을 구조체 안에 두고, 
	함수의 정의를 구조체 밖으로 빼내는 것이다

	다만 빼낸 다음에 해당 함수가 어디에 정의되어 있는지에 대한 정보만 추가해주면 된다
	그리고 구조체 안에 함수가 정의되어 있으면 함수를 인라인으로 처리해라는 의미가 더불어 내포된다

	반면, 아래 예제처럼 함수를 구조체 밖으로 빼내면 이러한 의미가 사라진다
	따라서 인라인의 의미를 그대로 유지하려면 inline 키워드를 이용해서 인라인 처리를 명시적으로 지시해야한다
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

	void ShowCarState();	// 상태정보 출력
	void Accel();			// 엑셀, 속도증가
	void Break();			// 브레이크, 속도감소
	// inline void ShowCarState();
};

void Car::ShowCarState() 
{

	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() 
{

	if (fuelGauge <= 0) return;
	else fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{

		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() 
{

	if (curSpeed < CAR_CONST::BRK_STEP)
	{

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