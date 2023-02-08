/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : ������
	Polymorphism
		�����Լ��� ȣ�� ���迡�� ���� Ư���� ������ �� �����̻�
		����� ������ ����� �ٸ���
		��ü������ �����ϴµ� �־ �ſ� �߿��� ���
*/

#include <iostream>
using namespace std;

class First {

public:
	virtual void SimpleFunc() {

		cout << "First" << endl;
	}
};

class Second : public First {

public:
	virtual void SimpleFunc() {

		cout << "Second" << endl;
	}
};

int main(void) 
{

	First* ptr = new First();
	ptr->SimpleFunc();	// First
	delete ptr;	

	ptr = new Second();
	// ���� �����ϳ� �ٸ� ����� ����
	ptr->SimpleFunc();	// Second
	delete ptr;	
	return 0;
}