/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : dynamic_cast
	dynamic_cast���� �߻��� �� �ִ� ���ܻ�Ȳ
*/

#include <iostream>
using namespace std;

class SoSimple {

public:
	virtual void ShowSimpleInfo() {

		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {

public:
	void ShowSimpleInfo() {

		cout << "Socomplex Derived Class" << endl;
	}
};

int main(void)
{

	SoSimple simObj;
	SoSimple& ref = simObj;

	try {

		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);	// ���� �߻�
															// NULL ���� ���޵ȴ�
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt) {

		cout << expt.what() << endl;	// what�޼ҵ�� ������ ������ ���ڿ��� ��ȯ
										// Bad dynamic_cast!
	}
	return 0;
}