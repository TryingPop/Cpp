/*
날짜 : 2023. 2. 3
이름 : 배성훈
내용 : 상속의 접근방식
	1단계 : 문제의 제시
		상속과 더불어 다형성의 개념을 적용해야만 해결 가능한 문제를 먼저 제시한다.
	
	2단계 : 기본개념 소개 
		상속의 문법적 요소를 하나씩 소개해 나간다.
		그리고 그 과정에서 앞서 제시한 문제의 해결책을 함께 고민해 나간다.

	3단계 : 문제의 해결
		처음 제시한 문제를, 상속을 적용하여 해결한다.

	기존에 정의해 놓은 클래스의 재활용을 목적으로 만들어진 문법적 요소가 상속이다.

	초기 상황 - 기능상에 문제는 없다

	추후 추가 고용형태 등장과
	급여 주는 방법이 확장되는 경우에 확장성에 문제가 생긴다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 데이터적 성격이 강한 클래스
class PermanentWorker {

private:
	char name[100];
	int salary;		// 매달 지불해야하는 급여액

public:
	PermanentWorker(const char* name, int money) 
		: salary(money) {

		strcpy(this->name, name);
	}

	int GetPay() const {

		return salary;
	}

	void ShowSalaryInfo() const {

		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

// 기능적 성격이 강한 클래스 - 컨트롤 클래스 또는 핸들러 클래스
class EmployeeHandler {

private:
	PermanentWorker* empList[50];
	int empNum;

public:
	EmployeeHandler()
		: empNum(0) { }

	// 새로운 직원정보의 등록
	void AddEmployee(PermanentWorker* emp) {

		empList[empNum++] = emp;
	}

	// 모든 직원의 이번 달 급여정보 출력
	void ShowAllSalaryInfo() const {

		for (int i = 0; i < empNum; i++) {

			empList[i]->ShowSalaryInfo();
		}
	}

	// 이번 달 급여의 총액 출력
	void ShowTotalsalary() const {

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

	// 직원 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalsalary();
	return 0;
}