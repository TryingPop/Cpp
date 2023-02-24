/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : catch���� ���ǻ���
	���ܰ� �߻��ϸ� ���� �����͸� ���޹��� �� �ִ� catch ����� ������ �Ʒ��� ã�� ��������
	�׸��� ������ catch ����� ã�� �Ǹ�, �ش� catch ����� ����Ǹ鼭 ������ ó���� �Ϸᰡ �ȴ�

	�̷��� Ư�� ������ ��Ϲ�ġ�� ��������
*/

#include<iostream>
using namespace std;

class AAA {

public:
	void ShowYou() {

		cout << "AAA exception!" << endl;
	}
};

class BBB : public AAA {

public:
	void ShowYou() {

		cout << "BBB exception!" << endl;
	}
};

class CCC : public BBB {

public:
	void ShowYou() {

		cout << "CCC exception!" << endl;
	}
};

void ExceptionGenerator(int expn) {

	if (expn == 1) {

		throw AAA();
	}
	else if (expn == 2) {

		throw BBB();
	}
	else {

		throw CCC();
	}
}

int main(void) {

	try {

		ExceptionGenerator(3);				// CCC Exception ����
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (AAA& expn) {

		cout << "catch(AAA& expn)" << endl;	// ���
		expn.ShowYou();						// AAA exception ���
	}
	catch (BBB& expn) {

		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC& expn) {

		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}

	// ���� ��Ī�Ǵ� ��츦 ����Ϸ��� �Ʒ��� ���� �ϸ�ȴ�
	try {

		ExceptionGenerator(3);				// CCC Exception ����
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (CCC& expn) {

		cout << "catch(CCC& expn)" << endl;	// ���
		expn.ShowYou();						// CCC Exception ���
	}
	catch (BBB& expn) {

		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA& expn) {

		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	return 0;
}