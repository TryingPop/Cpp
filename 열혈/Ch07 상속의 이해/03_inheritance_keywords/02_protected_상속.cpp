/*
��¥ : 2023. 2. 4
�̸� : �輺��
���� : ������ ������ ���
	protected ���
		- protected���� ������ ������ ���� ����� protected�� ������Ѽ� ����ϰڴ�
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

class Derived : protected Base { };	// empty!
									// Base�� public ��Ʈ�� protected�� ���Ѵٰ� ���� �ȴ�
									// �� num3�� Derived �ȿ��� protected, Base �����ڵ� Derived �ȿ��� protected
int main(void) 
{
	
	Derived drv;
	// cout << drv.num3 << endl; // ������ ���� �߻�
	return 0;
}