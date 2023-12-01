/*
��¥ : 2023. 2. 16
�̸� : �輺��
���� : ������ ������
	-> �����Ͱ� ����Ű�� ��ü�� ����� ����
	* �����Ͱ� ����Ű�� ��ü�� ����

	�� �� �������� �����ε��� �Ϲ����� �������� �����ε��� �ణ�� ���̰� �ִ�
	�� �� �� �����ڰ� �ϳ��� ���� �������� ���·� �����ε� �ȴ�

	���� 480p �����ϱ�

	�Ʒ��� �����ε� ����� �����̴�
*/

#include <iostream>
using namespace std;

class Number {

private:
	int num1;
	int num2;
	int num3;

public:
	Number(int n1)
		:num1(n1), num2(0), num3(0) { 
	
		cout << "Create n1" << endl;
	}

	Number(int n1, int n2, int n3)
		: num1(n1), num2(n2), num3(n3) {

		cout << "Create n1, n2, n3" << endl;
	}

	void ShowData() const {

		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}

	// ���� 480p �� ���ϸ�
	// �� �޼ҵ������ private ����鿡 ���ٰ����ϴٰ� �Ѵ�
	// ������ �����ϵ� ������ �������� const ������ ���ָ� �ȴ�
	Number* operator->() {

		return this;
	}

	Number& operator*() {

		return *this;
	}
};

int main(void)
{

	Number* num1 = new Number(20, 0, 0);	// create
	// ��� ���� ���� ���
	(*num1) = { 30, 0, 0 };					// create 
											// �����ڸ� �̿��� private ��������� 
											// ���� �����ϴ°� ����

	// num1 = 30;							// ������ ����
	// num1->num;							// ������ ����

	num1->ShowData();						// 30, 0, 0
	(*num1).ShowData();						// 30, 0, 0
	// num1.ShowData();						// ������ ����

	Number num2(40, 2, 2);
	(*num2) = 50;							// create, ������ ���� �ȵ�
	// num2 = { 50, 2 };					// ������ ����
	// num2->num;							// ������ ����

	(*num2).ShowData();						// 50, 2, 2 ������ ���Ǿȵ�
	num2.ShowData();						// 50, 2, 2 
	num2->ShowData();						// 50, 2. 2 ������ ���Ǿȵ�

	return 0;
}