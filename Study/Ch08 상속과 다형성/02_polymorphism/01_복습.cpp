/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : ���� Ŭ������ �����ͷ� ��ü�� ����
	���� ���� ��� �� ����
*/

#include <iostream>
using namespace std;

class Simple { };
class Complex : public Simple { };

class Base {

public:
	void BaseFunc() {

		cout << "Base Function" << endl;
	}
};

class Derived : public Base {

public:
	void DerivedFunc() {

		cout << "Derived Function" << endl;
	}
};

int main(void)
{

	// Simple Ŭ������ ������ ���� 
	// Simple Ŭ������ Simple Ŭ������ ���� Ŭ������ new Ű���带 �̿��� �����Ѵ�
	Simple* sim1 = new Simple;
	Simple* sim2 = new Complex;

	Base* bptr1 = new Derived;
	// bptr1->DerivedFunc();	// ������ ���� 
								// C++ �����Ϸ��� ������ ������ ���ɼ� ���θ� �Ǵ��� ��, �������� �ڷ����� �������� �Ǵ�
								// ���� ����Ű�� ��ü�� �ڷ����� �������� �Ǵ����� �ʴ´�
	// Derived dptr1 = bptr1;	// ������ ����

	Derived* dptr2 = new Derived;
	Base* bptr2 = dptr2;

	return 0;
}