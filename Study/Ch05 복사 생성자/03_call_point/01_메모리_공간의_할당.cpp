/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : �޸� ������ �Ҵ�� �ʱ�ȭ
	���ÿ� �Ͼ�� ��Ȳ
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;
};


int SimpleFunc(int n) {

	return n++;	// ��ȯ�ϴ� ���� �޸� ������ �Ҵ�Ǹ鼭 ���ÿ� �ʱ�ȭ!
}

SoSimple SimpleFuncObj(SoSimple obj) {

	return obj;	// ���� ���������� ��ȯ�ϴ� ���� �޸� ������ �Ҵ�ǰ� ���ÿ� �ʱ�ȭ!
}

int main(void)
{

	// �Ҵ�� ���ÿ� �ʱ�ȭ
	int num1 = 10;
	int num2 = num1;

	SimpleFunc(num1); // ȣ��Ǵ� ���� �Ű����� n�� �Ҵ�� ���ÿ� �ʱ�ȭ!

	// ���� �ڵ带 ���� ��ȯ ���� �޸𸮿� �Ҵ�Ǵ� ���� �� �� �ִ�
	cout << SimpleFunc(num2) << endl;

	// �Ҵ�� ���ÿ� �ʱ�ȭ
	SoSimple obj1;
	SoSimple obj2 = obj1;	// ���޵Ǵ� ���ڷ� �ʱ�ȭ

	SimpleFuncObj(obj1);	// ���� �����ϴ�
}