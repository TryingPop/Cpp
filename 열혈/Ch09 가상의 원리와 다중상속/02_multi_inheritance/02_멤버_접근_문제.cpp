/*
��¥ : 2023. 2. 10
�̸� : �輺��
���� : ���߻���� ������
	��� ������ ����
		�� Ŭ������ ������ �̸��� ����� �ִ� ��� �߻��ϴ� �����̴�
*/

#include<iostream>
using namespace std;

class BaseOne {

public:
	void SimpleFunc() {

		cout << "BaseOne" << endl;
	}
};

class BaseTwo {

public:
	void SimpleFunc() {

		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo {

public:
	void ComplexFunc() {

		// SimpleFunc(); // ������ ����
		// �ذ���
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{

	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}