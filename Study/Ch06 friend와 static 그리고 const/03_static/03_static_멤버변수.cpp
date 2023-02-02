/*
��¥ : 2023. 2. 2
�̸� : �輺��
���� : static �������(Ŭ���� ����)
	�Ϲ����� ��������� �޸� Ŭ������ �ϳ����� ����

	static ������ �ʱ�ȭ ��� ����
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	static int simObjCnt;

public:
	SoSimple() {

		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

int SoSimple::simObjCnt = 0;	// static ������ �ʱ�ȭ ���
								// �̰� �����ָ� vs������ �������
								// �ٸ� ���� �����Ⱚ�� �ʱⰪ�̶� �� �� ���� ��

class SoComplex {

private:
	static int cmxObjCnt;

public:
	SoComplex() {

		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}

	SoComplex(SoComplex& copy) {

		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

int SoComplex::cmxObjCnt = 0;

class SoOdd {

private:
	static int oddObjCnt;

public:
	SoOdd() {
		oddObjCnt = 0;	// static������ �̹� �޸� ������ �Ҵ��� �̷���� ������ ��ü�� �����ɶ����� �Ź� 0���� �ʱ�ȭ
		oddObjCnt++;
		cout << oddObjCnt << "��° SoOdd ��ü" << endl;
	}
};

int SoOdd::oddObjCnt = 0;

int main(void) 
{

	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	SoOdd odd1;
	SoOdd odd2;
	return 0;
}

