/*
��¥ : 2023. 2. 10
�̸� : �輺��
���� : ���� ���
	���� ������ ��ȣ���� ���� �ľ��غ���
*/

#include <iostream>
using namespace std;

class Base {

public:
	Base() {
		cout << "Base Constructor" << endl;
	}

	void SimpleFunc() {

		cout << "BaseOne" << endl;
	}
};

class MiddleDerivedOne : virtual public Base {

public:
	MiddleDerivedOne()
		: Base() {
	
		cout << "MiddleDerivedOne Constructor" << endl;
	}

	void MiddleFuncOne() {

		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base {

public:
	MiddleDerivedTwo()
		: Base() {

		cout << "MiddleDerivedTwo Constructor" << endl;
	}

	void MiddleFuncTwo() {

		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {

public:
	LastDerived()
		: MiddleDerivedOne(), MiddleDerivedTwo() {

		cout << "LastDerived Constructor" << endl;
	}

	void ComplexFunc() {

		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{

	cout << "��ü���� �� ....." << endl;
	LastDerived ldr;	// Base, MiddleOne, MiddleTwo, Last ������ ȣ��ȴ� 
						// Base�� �� ���� ȣ��ȴ�
						// Last Ŭ������ Base�� ���������� �� �� ����Ѵ�
	cout << "��ü���� �� ....." << endl;
	ldr.ComplexFunc();	// virtual ������ �ȵǾ��� �ִٸ� 
						// MiddleDerivedOne::SimpleFuncó�� ��� SimpleFunc�� ȣ���ϴ��� ���������Ѵ�
						// ���� ����� �����ν� 1�� ����ϰ� �ߴ�
						// virtual Ű���尡 ���ٸ� ��ȣ�ϴٴ� ������ ���� �߻��ϰ� Base Ŭ������ �ι� ȣ��ȴ�
	return 0;
}