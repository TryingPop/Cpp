/*
��¥ : 2023. 2. 10
�̸� : �輺��
���� : �����Լ��� ���ۿ����� �����Լ� ���̺�
	C++�� C���� ���� ������ �� �� �ִ�
	�����Լ��� �����ϱ� ���� ����

	�����Լ��� ���ԵǸ� �����Լ� ���̺��� ������ ȣ��� �Լ��� �����Ǳ� ������
	C++�� C���� ���� �̹��ϰ� ���� ���� �� �ۿ� ����
*/

#include <iostream>
using namespace std;

class AAA {

private:
	int num1;
	
public:
	// �����ϸ� �����Լ��� �����ϴ� Ŭ������ ���� 
	// �޼ҵ��� �̸��� Ű�� �ּҸ� ������ ���� �����Լ� ���̺��� �����Ѵ�
	virtual void Func1() {

		cout << "Func1" << endl;
	}

	virtual void Func2() {

		cout << "Func2" << endl;
	}
};

class BBB : public AAA {

private:
	int num2;

public:
	// AAA�� ���������� �����Լ� ���̺� ����
	// �׷��� AAA Ŭ������ �������̵� �� �����Լ� Func1�� ���� ������ �������� �ʴ´�
	virtual void Func1() {

		cout << "BBB::Func1" << endl;
	}

	void Func3() {

		cout << "Func3" << endl;
	}
};

int main(void)
{

	AAA* aptr = new AAA();
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();
	return 0;
}