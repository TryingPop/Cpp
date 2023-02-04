/*
��¥ : 2023. 2. 3
�̸� : �輺��
���� : ����� ���ٹ��
	1�ܰ� : ������ ����
		��Ӱ� ���Ҿ� �������� ������ �����ؾ߸� �ذ� ������ ������ ���� �����Ѵ�.
	
	2�ܰ� : �⺻���� �Ұ� 
		����� ������ ��Ҹ� �ϳ��� �Ұ��� ������.
		�׸��� �� �������� �ռ� ������ ������ �ذ�å�� �Բ� ����� ������.

	3�ܰ� : ������ �ذ�
		ó�� ������ ������, ����� �����Ͽ� �ذ��Ѵ�.

	������ ������ ���� Ŭ������ ��Ȱ���� �������� ������� ������ ��Ұ� ����̴�.

	�ʱ� ��Ȳ - ��ɻ� ������ ����

	���� �߰� ������� �����
	�޿� �ִ� ����� Ȯ��Ǵ� ��쿡 Ȯ�强�� ������ �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// �������� ������ ���� Ŭ����
class PermanentWorker {

private:
	char name[100];
	int salary;		// �Ŵ� �����ؾ��ϴ� �޿���

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

// ����� ������ ���� Ŭ���� - ��Ʈ�� Ŭ���� �Ǵ� �ڵ鷯 Ŭ����
class EmployeeHandler {

private:
	PermanentWorker* empList[50];
	int empNum;

public:
	EmployeeHandler()
		: empNum(0) { }

	// ���ο� ���������� ���
	void AddEmployee(PermanentWorker* emp) {

		empList[empNum++] = emp;
	}

	// ��� ������ �̹� �� �޿����� ���
	void ShowAllSalaryInfo() const {

		for (int i = 0; i < empNum; i++) {

			empList[i]->ShowSalaryInfo();
		}
	}

	// �̹� �� �޿��� �Ѿ� ���
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

	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalsalary();
	return 0;
}