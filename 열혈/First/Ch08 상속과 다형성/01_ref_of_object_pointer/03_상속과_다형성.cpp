/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 교재 276p 내용
	Ch07 에서 '오렌지미디어 급여관리 확장성 문제'의 해결 2

	함수의 오버라이딩
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

	void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {

private:
	int workTime;
	int payPerHour;

public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) { }

	void AddWorkTime(int time) {

		workTime += time;
	}

	int GetPay() const {	// 이 달의 급여

		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const {

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

	int GetPay() const {

		return PermanentWorker::GetPay()	// PermanentWorker의 GEtPay함수 호출
			+ (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const {	// 다음 함수를 오버라이딩 하지 않고 쓰면
									// GetPay함수가 SalesWorker께 아닌 PermanentWork의 GetPay를 호출하기 때문에 별도로 정의했다

		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
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

		/*
		for (int i =0; i < empNum; i++) {

			empList[i]->ShowSalaryInfo();
		}
		*/
	}

	void ShowTotalsalary() const {

		int sum = 0;

		/*
		for (int i = 0; i < empNum; i++) {

			sum += empList[i]->GetPay();
		}
		*/
		
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

	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	//임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);	// 5시간 일한결과 등록
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);	// 영업실적 7000

	// seller->ShowSalaryInfo();	// 1700, SalesWork의 GetPay 호출
	// ((PermanentWorker*)seller)->ShowSalaryInfo();	// 1000, PermanentWorker의 GetPay 호출
	handler.AddEmployee(seller);


	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalsalary();
	return 0;
}