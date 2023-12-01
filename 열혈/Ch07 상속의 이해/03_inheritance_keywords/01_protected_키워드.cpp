/*
��¥ : 2023. 2. 4
�̸� : �輺��
���� : protected�� ����� ����� ����ϴ� ������ ����
	private : �ڽŸ� ���� ����
	protected : ���� Ŭ���������� ���� ����, �ܺο����� ���� �Ұ���
	public : ��𿡼��� ���� ����

	���� Ŭ������ �̸� ����ϴ� ���� Ŭ���� ���̿����� ���������� �������� �� ����
*/

#include <iostream>
using namespace std;

class Base {

private:
	int num1;

protected:
	int num2;

public:
	int num3;

	void ShowData() {

		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}
};

class Derived : public Base {

public:
	void ShowBaseMember() {

		// cout << num1 << endl; // ������ ����
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

