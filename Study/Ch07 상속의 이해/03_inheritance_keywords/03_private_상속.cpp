/*
��¥ : 2023. 2. 4
�̸� : �輺��
���� : ������ ������ ���
	private ���
		private���� ������ ������ ���� ����� private���� ������� ����ϰڴ�
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

	Base()
		: num1(1), num2(2), num3(3) { }
};

class Derived : private Base { };	// empty!
									// num2, num3�� Derived �ȿ��� private ����� ���Ѵ�

class DeDerived : public Derived { };	// DeDerived���� num2�� num3�� ������ �� ����

int main(void)
{

	Derived drv;
	// cout << drv.num2 << endl; // ������ ����
}
