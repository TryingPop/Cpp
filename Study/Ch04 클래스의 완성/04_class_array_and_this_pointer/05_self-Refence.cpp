/*
��¥ : 2023. 1. 29
�̸� : �輺��
���� : self Reference
	��ü �ڽ��� ������ �� �ִ� ������

	this �����͸� �̿��� ��ü�� �ڽ��� ������ ����� �� �ִ� 
	�������� ��ȯ���� �����غ���
*/

#include<iostream>
using namespace std;

class SelfRef {

private:
	int num;

public:
	SelfRef(int n) : num(n) {

		cout << "��ü����" << endl;
	}

	SelfRef& Adder(int n) {

		num += n;
		return *this;
	}

	SelfRef& ShowTwoNumber() {

		cout << num << endl;
		return *this;
	}
};

int main(void)
{

	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();	// 5
	ref.ShowTwoNumber();	// 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	// 6,  8 
															// Adder(1), ShowTwoNumber(), Adder(2), ShowTwoNumber()
															// ������ �޼ҵ尡 ȣ����� �� �� �ִ�
	return 0;
}