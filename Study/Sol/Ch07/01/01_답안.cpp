/*
날짜 : 2023. 2. 7
이름 : 배성훈
내용 : 교재 294p 문제1
	앞서 상속관계에 놓여있는 클래스의 생성자 정의 및 호출 방식에 대해 설명하였다.
	이 내용을 바탕으로 다음 클래스에 적절한 생성자를 삽입해보자. 그리고 이의 확인을 위한 main 함수를 적절히 정의해보자.
	class Car {	// 기본 염료 자동차

	private:
		int gasolineGauge;
	public:
		int GetGasGauge() {
			return gasolineGauge;
		}
	};
	class HybridCar : public Car {	// 하이브리드 자동차
	private:
		int electricGauge;
	public:
		int GetElecGauge() {

			return electricGauge;
		}
	};
	class HybridWaterCar : public HybridCar	{	// 하이브리드 워터카
	private:
		int waterGauge;
	public:
		void ShowCurrentGauge() {
			cout << "잔여 가솔린: " << GetGasGauge() << endl;
			cout << "잔여 전기량: " << GetElecGauge() << endl;
			cout << "잔여 워터량: " << waterGauge << endl;
		}
	};
	참고로, Car 클래스는 가솔린으로 동작하는 자동차를 표현한 것이고,
	HybridCar 클래스는 가솔린과 전기로 동작하는 자동차를 표현한 것이다.
	그리고 마지막으로 HybridWaterCar 클래스는 가솔린과 전기뿐만 아니라,
	물도 동시에 연료로 사용할 수 있는, 가상의 자동차를 표현한 것이다.
	그러나 이 문제는 위의 클래스들이 의미하는 바를 몰라도 해결이 가능하다.

	그리고 위의 코드에서는 앞서 보인 예제들과 달리 상속의 깊이(몇 단계에 걸쳐서 상속이 이뤄지고 있는가를 의미함)가 한 단계 더해졌지만,
	그로 인해서 여러분이 더 알아야 할 문법적 지식이 있거나, 해석하는 방식에 있어서 차이가 있는 것은 아니다
*/

#include <iostream>
using namespace std;

class Car {	// 기본 연료 자동차

private:
	int gasolineGauge;

public:
	Car(int gas)
		: gasolineGauge(gas) { }

	int GetGasGauge() {

		return gasolineGauge;
	}
};

class HybridCar : public Car {	// 하이브리드 자동차

private:
	int electricGauge;

public:
	HybridCar(int gas, int elec)
		: Car(gas), electricGauge(elec) { }

	int GetElecGauge() {

		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {	// 하이브리드 워터카

private:
	int waterGauge;

public:
	HybridWaterCar(int gas, int elec, int water)
		: HybridCar(gas, elec), waterGauge(water) { }

	void ShowCurrentGauge() {

		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void) 
{

	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}