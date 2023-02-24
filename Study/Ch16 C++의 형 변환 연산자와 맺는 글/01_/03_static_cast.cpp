/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : static_cast
	dynamic_cast 연산자와 동일한 형태이다
	static_cast<T>(expr)

	dynamic_cast 연산자를 사용할 수 있는 경우에는 dynamic_cast 연산자를 이용해 안정성을 높여야하고
	그 이외의 경우에는 정말 책임질 수 있는 상황에만 static_cast 연산자를 이용해야한다

	static_cast가 dynamic_cast보다 속도가 빠르다

	static_cast 연산자는 기본 자료형 간의 형 변환과 클래스의 상속관계에서의 형 변환만을 허용한다
	반면 C언어의 형 변환 연산자는 말도 안되는 형 변환도 허용하므로 static_cast 연산자를 이용하는 것이 좋다
*/

#include<iostream>
using namespace std;

class Car {

private:
	int fuelGauge;

public:
	Car(int fuel)
		: fuelGauge(fuel) { }

	void ShowCarState() const {

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

		cout << "화물의 무게: " << freightWeight << endl;
	}
};

int main(void)
{

	Car* pcar1 = new Truck(80, 120);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);		

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);	// 컴파일 ok 
													// 그러나 의도하지 않은 상황을 프로그래머가 책임져야한다

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);
	return 0;
	return 0;
}