/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���������
	����Ʈ ���� ������
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2) { }
	
	/*
	// �� �ּ��� �ڵ尡 ����Ʈ ���� ������
	SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2) { }
	*/
};