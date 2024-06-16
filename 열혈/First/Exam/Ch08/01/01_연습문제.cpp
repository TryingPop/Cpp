/*
��¥ : 2023. 2. 9
�̸� : �輺��
���� : ���� 354p ����1
	���� EmployeeManager4.cpp�� Ȯ���Ͽ� ���� Ư���� �ش��ϴ� ForeignSalesWorker Ŭ������ �߰��� �����غ���.
		"������ ���� �� �Ϻδ� �����갣���� ���尳ô�� �����ϰ� �ִ�.
		�Ϻδ� �Ƹ�������, �� �Ϻδ� �׷��� ������ �ִ� �������� ����Ȱ���� ���� �߿� �ִ�.
		���� �̷��� �������� ������� ������ ��������� �����ϰ��� �Ѵ�."

	��������� ���޹���� '������ ���⵵'�� ���� ������ ���� ������,
	�ѹ� ������ ������ '���� ���⵵'�� ������� �ʴ´ٰ� �����Ѵ�
	(�̴� const ��������� ������ �����ϴ� ���̴�).
		����ũ A: �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 30%�� �߰��� �����Ѵ�.
		����ũ B: �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 20%�� �߰��� �����Ѵ�.
		����ũ C: �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 10%�� �߰��� �����Ѵ�.

	���� main �Լ��� �Բ� �����ϵ��� ForeignSalesWorker Ŭ������ �����ϱ� �ٶ��,
	Employee Ŭ������ ��ü ������ �Ұ����� �߻� Ŭ������ �����ϱ� �ٶ���.

	[main �Լ�]
	int main(void)
	{
		
		// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
		EmployeeHandler handler;

		// �ؿ� ������ ���
		ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
		fseller1->AddSalesResult(7000);		// �������� 7000
		handler.AddEmployee(fseller1);

		ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
		fseller2->AddSalesResult(7000);		// �������� 7000
		handler.AddEmployee(fseller2);

		ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
		fseller3->AddSalesResult(7000);		// �������� 7000
		handler.AddEmployee(fseller3);

		// �̹� �޿� �����ؾ� �� �޿��� ����
		handler.ShowAllSalaryInfo();
		return 0;
	}
	
	���� main �Լ����� ���̴� RISK_LEVEL �̸������� RISK_A, RISK_B, RISK_C�� enum������ ����� ����̴�.
	������ ���� ����̴�

	[������ ��]
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

	���� ���������� salary ������ �Ϲ� ������ ������ �޿� ������̸�(�⺻�޿� �󿩱��� ���� ���), risk pay�� ������翡 ���Ѵ�.
*/

// ���� ���� �ۼ� 2ȸ������ ���� �Ⱥ��� �ۼ��غ���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace RISK_LEVEL {

	enum {RISK_A = 1, RISK_B, RISK_C};

	float GetRiskRatio(int risk) {

		switch (risk) {

		case RISK_A:
			return 0.3f;

		case RISK_B:
			return 0.2f;

		case RISK_C:
			return 0.1f;

		default:
			return 1;
		}
	}
}

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

	virtual int GetPay() const {

		return 0;
	}

	virtual void ShowSalaryInfo() const = 0 { }
};

class PermanentWorker : public Employee {

private:
	int salary;		// �� �޿�

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
	int workTime;	// �� �޿� ���� �ð��� �հ�
	int payPerHour;	// �ð��� �޿�

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
	int salesResult;	// �� �ǸŽ���
	double bonusRatio;	// �󿩱� ����

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

class ForeignSalesWorker : public SalesWorker {

private:
	int riskRank;

public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskRank(risk) { }

	int GetPay() const {

		return (int)(SalesWorker::GetPay() * (1 + RISK_LEVEL::GetRiskRatio(riskRank)));
	}

	void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << SalesWorker::GetPay() * RISK_LEVEL::GetRiskRatio(riskRank) << endl;
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

	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// �ؿ� ������ ���
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);		// �������� 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();
	return 0;
}