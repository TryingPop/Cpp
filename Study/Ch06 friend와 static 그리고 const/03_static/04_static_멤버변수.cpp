/*
��¥ : 2023. 2. 2
�̸� : �輺��
���� : static �������
	static ��������� �� �ٸ� ���� ���
*/

#include<iostream>
using namespace std;

class SoSimple {

public:
	static int simObjCnt;

public:	// ���ʿ������� ������ �Լ��� ������ �������� �����ϱ⵵ ��
	SoSimple() {

		simObjCnt++;
	}
};

int SoSimple::simObjCnt = 0;

int main(void)
{

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;		// 0
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;		// 2
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;				// 2
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;				// 2
	return 0;
}