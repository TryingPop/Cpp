/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���� �������� �ʱ�ȭ
	Call by value ����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
	���� ���� �����ڰ� ȣ��Ǵ��� Ȯ���ϴ� ����
*/

#include <iostream>
using namespace std;

class SoSimple {

public:
	int num;

public:
	SoSimple(int n)
		: num(n) { }

	SoSimple(const SoSimple& copy)
		: num(copy.num) {
	
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	void ShowData() {

		cout << "num : " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob) {

	ob.ShowData();
}

int main(void) 
{

	SoSimple obj(7);
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFuncObj(obj);		// ������ ob�� ���Ӱ� obj�� ���� �������� �� �� �ִ�
							// �� ���� ������ ȣ�� > ob.ShowData() �����̴�
	cout << "�Լ�ȣ�� ��" << endl;
	return 0;
}