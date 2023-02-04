/*
��¥ : 2023. 2. 4
�̸� : �輺��
���� : HAS-A ������ �ٸ� ǥ����
	����� �ƴ� �ٸ� ������� ǥ��

	02���� �� Ȯ�强�� �� ����

	���� 331p ������ IS-A�� HAS-A �̿ܿ��� ǥ���� ������ ���Ѵٰ� �Ѵ�
	����, HAS-A�� ���� ���ذŶ� �Ѵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun {

private:
	int bullet;		// ������ �Ѿ��� ��

public:
	Gun(int bnum)
		: bullet(bnum) { }

	void Shot() {

		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {

private:
	int handcuffs;	// �����ϰ� �ִ� ������ ��
	Gun* pistol;	// �����ϰ� �ִ� ����

public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {

		if (bnum > 0) pistol = new Gun(bnum);
		else pistol = NULL;
	}

	void PutHandcuff() {

		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot() {

		if (pistol == NULL) cout << "Hut BBANG!" << endl;
		else pistol->Shot();
	}

	~Police() {

		if (pistol != NULL) delete pistol;
	}
};

int main(void) 
{

	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);	// ������ �������� ���� ����
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}