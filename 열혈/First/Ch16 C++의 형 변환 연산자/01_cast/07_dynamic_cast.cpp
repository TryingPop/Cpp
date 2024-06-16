/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : dynamic_cast
	Polymorphic Ŭ���� ����� �� ��ȯ
		��Ӱ��迡 �����ִ� �� Ŭ���� ���̿���,
		���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������ �����ͷ� �� ��ȯ�� ��쿡�� 
		dynamic_cast �����ڸ� ����Ѵ�

		�ݴ�� ��Ӱ��迡 �����ִ� �� Ŭ���� ���̿���,
		���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������ �����ͷ� �� ��ȯ�� ��쿡�� 
		static_ast �����ڸ� ����Ѵ�

		���� ���� Ŭ������ Polymorphic Ŭ�����̸�,
		dynamic_cast �����ڵ� ���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������������
		�� ��ȯ�� ����Ѵ�

		���⼭ Polymorphic Ŭ������ �ϳ� �̻��� �����Լ��� ���ϴ� Ŭ������ ���Ѵ�.
*/

#include<iostream>
using namespace std;

class SoSimple {	// Polymorphic Ŭ����
					// ShowSimpleInfo�� �����Լ� �̹Ƿ�

public:
	virtual void ShowSimpleInfo() {	// virtual�� �������� �ʾ��� �� ������ ���� �߻�

		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {	

public:
	void SowSimpleInfo() {	// �̰� ���� �����Լ�

		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{

	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}

