/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : polymorphic
	dynamic_cast�� �������� �� ��ȯ�� �����Ѵ�
	������ �ð��� �ƴ� ���� �ð��� �������� �˻��ϵ��� �����Ϸ��� ���̳ʸ� �ڵ带 �����Ѵ�
	�̷� ���� ���� �ӵ��� ��������

	�ݸ� static_cast�� ������ �� ��ȯ�� �ǵ��� ���̳ʸ� �ڵ带 �����ϱ� ������
	�� �����ڴ� �������� �������� �ʴ´�
	�ٸ� ���� �ӵ��� ������

	���� �������� simPtr�� SoComplex�� ����Ű�� ������ ����������
	�̹����� SoSimple�� ����Ű�� ��쿡 ���� ����
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

	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);

	if (comPtr == NULL) {

		cout << "�� ��ȯ ����" << endl;		// ���
	}
	else {

		comPtr->ShowSimpleInfo();
	}
	return 0;
}
