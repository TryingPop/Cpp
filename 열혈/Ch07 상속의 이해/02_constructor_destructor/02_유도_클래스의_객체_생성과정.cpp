/*
��¥ : 2023. 2. 4
�̸� : �輺��
���� : ���� Ŭ������ ��ü ��������
	����Ŭ����, ����Ŭ����, ���� Ŭ����, �θ� Ŭ���� ��� ���� ���̰�
	������ �����Ǵ� ���� ���� Ŭ����, ���� Ŭ����, ���� Ŭ����, �ڽ� Ŭ���� �̴�

	���� Ŭ������ �ڽ� Ŭ������ �ؼ��ϸ� �ȴ�

	���� Ŭ������ ��ü ���������� �˾ƺ��� ���̴�
	���⼭ ���� �߿��� ���� ���� Ŭ������ ������ ȣ���̴�

	�޸� �Ҵ� > ���� Ŭ���� ������ ȣ�� > ���� Ŭ���� ������ ȣ�� ��
*/

#include <iostream>
using namespace std;

class SoBase {

private:
	int baseNum;

public:
	SoBase()
		: baseNum(20) {
		
		cout << "SoBase()" << endl;
	}

	SoBase(int n)
		: baseNum(n) {

		cout << "SoBase(int n)" << endl;
	}

	void ShowBaseData() {

		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase {

private:
	int derivNum;

public:
	SoDerived()
		: derivNum(30) {

		cout << "SoDerived()" << endl;
	}

	SoDerived(int n)
		: derivNum(n) {

		cout << "SoDerived(int n)" << endl;
	}

	SoDerived(int n1, int n2)
		: SoBase(n1), derivNum(n2) {

		cout << "SoDerived(int n1, int n2)" << endl;
	}

	void ShowDerivData() {

		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void)
{

	cout << "case1....." << endl;
	SoDerived dr1;	// SoBase(), SoDerived() ������ ȣ��
	dr1.ShowDerivData();
	cout << "--------------------" << endl;

	cout << "case2....." << endl;
	SoDerived dr2(12);	// SoBase(), SoDerived(int n) ������ ȣ��
	dr2.ShowDerivData();
	cout << "--------------------" << endl;

	cout << "case3....." << endl;
	SoDerived dr3(23, 24);	// SoBase(int n), SoDerived(int n1, int n2) ������ ȣ��
	dr3.ShowDerivData();
	cout << "--------------------" << endl;
	return 0;
}