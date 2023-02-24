/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : 형 변환 연산자
	C 스타일의 형 변환의 문제점

	맞는 형 변환 연산인지는 모르지만, 무턱대고 형 변환 연산을 진행하는 아래 예제
*/

#include <iostream>
using namespace std;

class Car {

private:
	int fuelGauge;
public:
	Car(int fuel)
		: fuelGauge(fuel) { }

	void ShowCarState() {

		cout << "잔여 연료량: " << fuelGauge << endl;
	}
};

class Truck : public Car {

private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight) { }

	void ShowTruckState() {

		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

int main(void)
{

	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = (Truck*)pcar1;	// 문제 없어 보이는 형 변환
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;	// 문제가 바로 보이는 형 변환
	ptruck2->ShowTruckState();		// 화물의 무게에서 쓰레기 값을 준다
}