/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : dynamic_cast
	상속관계에서의 안전한 형변환

	dynamic_cast<T>(expr)
		<> 사이에 변환하고자 하는 자료형의 이름을 두고 객체의 포인터 또는 참조형이 와야한다
		() 사이에는 변환의 대상이와야 한다
		그리고 요구한 형 변환이 적절한 경우에는 형 변환된 데이터를 반환하지만
		요구한 형 변환이 적절하지 않는 경우에는 컴파일 에러가 발생

		적절하지 않는 경우는
			상속관계에 놓여 있는 두 클래스 사이에서 유도 클래스의 포인터 및 참조형 데이터를
			기초 클래스의 포인터 및 참조형 데이터로 형 변환하는 경우
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

class Truck : public Car{

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
	// Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);	// 컴파일 에러

	Car* pcar2 = new Car(120);
	// Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);	// 컴파일 에러

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);
	return 0;
	return 0;
}