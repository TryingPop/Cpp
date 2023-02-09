/*
날짜 : 2023. 2. 9
이름 : 배성훈
내용 : 교재 354p 문제1
	예제 EmployeeManager4.cpp를 확장하여 다음 특성에 해당하는 ForeignSalesWorker 클래스를 추가로 정의해보자.
		"영업직 직원 중 일부는 오지산간으로 시장개척을 진행하고 있다.
		일부는 아마존에서, 또 일부는 테러의 위험이 있는 지역에서 영업활동을 진행 중에 있다.
		따라서 이러한 직원들을 대상으로 별도의 위험수당을 지급하고자 한다."
	위험수당의 지급방식은 '위험의 노출도'에 따라서 다음과 같이 나뉘며,
	한번 결정된 직원의 '위험 노출도'는 변경되지 않는다고 가정한다
	(이는 const 멤버변수의 선언을 유도하는 것이다).
		리스크 A: 영억직의 기본급여와 인센티브 합계 총액의 30%를 추가로 지급한다.
		리스크 B: 영업직의 기본급여와 인센티브 합계 총액의 20%를 추가로 지급한다.
		리스크 C: 영업직의 기본급여와 인센티브 합계 총액의 10%를 추가로 지급한다.
	다음 main 함수와 함께 동작하도록 ForeignSalesWorker 클래스를 정의하기 바라며,
	Employee 클래스는 객체 생성이 불가능한 추상 클래스로 정의하기 바란다.
	[main 함수]
	int main(void)
	{

		// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
		EmployeeHandler handler;
		// 해외 영업직 등록
		ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
		fseller1->AddSalesResult(7000);		// 영업실적 7000
		handler.AddEmployee(fseller1);
		ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
		fseller2->AddSalesResult(7000);		// 영업실적 7000
		handler.AddEmployee(fseller2);
		ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
		fseller3->AddSalesResult(7000);		// 영업실적 7000
		handler.AddEmployee(fseller3);
		// 이번 달에 지불해야 할 급여의 정보
		handler.ShowAllSalaryInfo();
		return 0;
	}

	위의 main 함수에서 보이는 RISK_LEVEL 이름공간의 RISK_A, RISK_B, RISK_C는 enum형으로 선언된 상수이다.
	다음은 실행 결과이다
	[실행의 예]
	name: Hong
	salary: 1700
	risk pay: 510
	sum: 2210
	name: Yoon
	salary: 1700
	risk pay: 340
	sum: 2040
	name: Lee
	salary: 1700
	risk pay: 170
	sum: 1870
	위의 실행결과에서 salary 내역은 일반 영업직 직원의 급여 계산결과이며(기본급에 상여금을 더한 결과), risk pay가 위험수당에 속한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee {

private:
	char name[100];

public:
	Employee(const char* name) {

		strcpy(this->name, name);
	}

	void ShowYourName() const {

		cout << "name: " << name << endl;
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {

private:
	int salary;		// 월 급여

public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money) { }

	int GetPay() const {

		return salary;
	}

	virtual void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {

private:
	int workTime;	// 이 달에 일한 시간의 합계
	int payPerHour;	// 시간당 급여

public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) { }

	void AddWorkTime(int time) {

		workTime += time;
	}

	int GetPay() const {

		return workTime * payPerHour;
	}

	virtual void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {

private:
	int salesResult;	// 월 판매실적
	double bonusRatio;	// 상여금 비율

public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }

	void AddSalesResult(int value) {

		salesResult += value;
	}

	virtual int GetPay() const {

		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	virtual void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL {

	enum{RISK_A = 30, RISK_B = 20, RISK_C = 10};
}

class ForeignSalesWorker : public SalesWorker {

private:
	const int riskLevel;

public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskLevel(risk) { }

	int GetRiskPay() const {

		return (int)(SalesWorker::GetPay() * (riskLevel / 100.0));
	}

	int GetPay() const {

		return SalesWorker::GetPay() + GetRiskPay();
	}

	void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {

private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler()
		: empNum(0) { }

	void AddEmployee(Employee* emp) {

		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const {

		for (int i = 0; i < empNum; i++) {

			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const {

		int sum = 0;
		for (int i = 0; i < empNum; i++) {

			sum += empList[i]->GetPay();
		}

		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler() {

		for (int i = 0; i < empNum; i++) {

			delete empList[i];
		}
	}
};

int main(void) 
{

	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 해외 영업직 등록
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);		// 영업실적 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	return 0;
}