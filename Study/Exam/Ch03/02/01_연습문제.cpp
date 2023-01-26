/*
��¥ : 2023. 1. 26
�̸� : �輺��
���� : ���� 135p ����1
	���� ����� Calculator Ŭ������ ������ ����.
	�⺻������ ���ϴ� ����� ����, ����, ���� �׸��� �������̸�, 
	������ �� �� ���� ��� ������ �� �� �����ߴ��� ��ϵǾ�� �Ѵ�.
	�Ʒ��� main �Լ��� ������ ���� �����ϴ� Calculator Ŭ������ �����ϸ� �ȴ�.
	��, ��������� private����,
	����Լ��� public���� ��������.
	�̷��� �����ϴ� ������ ���ؼ��� ���� Chapter���� �ڼ��� ����Ѵ�.

	int main(void)
	{

		Calculator cal;
		cal.Init();
		cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
		cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
		cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
		cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
		cal.ShowOpCount();
		return 0;
	}

	������ ��
	3.2 + 2.4 = 5.6
	3.5 / 1.7 = 2.05882
	2.2 - 1.5 = 0.7
	4.9 / 1.2 = 4.08333
	����: 1 ����: 1 ����: 0 ������: 2 
*/

#include <iostream>
using namespace std;

class Calculator {

private:
	int addCnt;
	int minCnt;
	int mulCnt;
	int divCnt;

public:
	void Init() {

		addCnt = 0;
		minCnt = 0;
		mulCnt = 0;
		divCnt = 0;
	};
	
	float Add(float num1, float num2) {

		addCnt++;
		return num1 + num2;
	};

	float Min(float num1, float num2) {

		minCnt++;
		return num1 - num2;
	}

	float Mul(float num1, float num2) {

		mulCnt++;
		return num1 * num2;
	};

	float Div(float num1, float num2) {

		divCnt++;
		return num1 / num2;
	}

	void ShowOpCount() {

		cout << "����: " << addCnt << ' ' << "����: " << minCnt << ' ' << "���� : " << mulCnt << ' ' << "������: " << divCnt << endl;
	}
};

int main(void) 
{

	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

