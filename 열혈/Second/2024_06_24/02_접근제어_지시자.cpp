/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : 접근제어 지시자(접근제어 레이블)
	교재 p122 ~ 126

	C++에서 접근제어 지시자는 총 3가지가 존재한다
		public, protectd, private

	이들이 의미하는 바는
	public 어디서든 접근허용
	protected 상속관계에 놓여있을 때, 유도 클래스에서의 접근 허용
	private 클래스 내(클래스 내에 정의된 함수)에서만 접근 허용

	protected는 상속과 관련이 있으므로 나중에 살펴보고,
	public과 private부터 보자

	접근제어 지시자가 선언되면,
	그 이후에 등장하는 변수나 함수는 A에 해당하는 범위 내에서 접근이 가능하다

	그러나 새로운 접근제어 지시자 B가 선언되면,
	그 이후로 등장하는 변수나 함수는 B에 해당하는 범위 내에서 접근이 가능하다

	함수의 정의를 클래스 밖으로 빼도,
	이는 클래스의 일부이기 때문에,
	함수 내에서는 private로 선언된 변수에 접근이 간으하다

	키워드 struct를 이용해서 정의한 구조체에
	선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면
	모든 변수와 함수는 public으로 선언된다
	(struct도 접근제어 지시자를 선언할 수 있다)

	키워드 class를 이용해서 정의한 클래스에 선언된 변수와 함수에
	별도의 접근제어 지시자를 선언하지 않으면,
	모든 변수와 함수는 private로 선언된다
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

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

class Car 
{

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel) 
{

	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() 
{

	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
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