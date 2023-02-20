/*
��¥ : 2023. 2. 21
�̸� : �輺��
���� : ���� 452p ����1
	Chapter 07������ ���� HASComposite.cpp(���� 309p)���� ������ �� Ŭ������ �����Ͽ���.
	class Gun {

	private:
		int bullet;	// ������ �Ѿ��� ��
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
		int handcuffs;	// ������ ������ ��
		Gun* pistol;	// �����ϰ� �ִ� ����

	public:
		Police(int bnum, int bcuff)
			: handcuffs(bcuff) {
			if (bnum > 0) {
				pistol = new Gun(bnum);
			}
			else {
				pistol = NULL;
			}
			void PutHandcuff() {
				cout << "SNAP!" << endl;
				handcuffs--;
			}
			void Shot() {

				if (pistol == NULL) {
					cout << "Hut BBANG!" << endl;
				}
				else {
					pistol->Shot();
				}
			}
			~Police() {
				if (pistol != NULL) {
					delete pistol
				}
			}
		}
	}
	�̿� Police Ŭ������ ������� ���� ���簡 �̷�������
	�븳 �����ڿ� ���� �����ڸ� ���ÿ� �����ϰ�
	���� Ȯ���� ���� main �Լ��� ������ �����غ���.
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
	int handcuffs;	// ������ ������ ��
	Gun* pistol;	// �����ϰ� �ִ� ����

public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {

		if (bnum > 0) {

			pistol = new Gun(bnum);
		}
		else {

			pistol = NULL;
		}
	}

	Police(const Police& ref)
		: handcuffs(ref.handcuffs) {

		if (ref.pistol != NULL) {

			pistol = new Gun(*ref.pistol);	// Gun�� ���� ������ ȣ��
		}
		else {

			pistol = NULL;
		}
	}

	Police& operator=(const Police& ref) {

		if (pistol != NULL) {

			delete pistol;
		}

		if (ref.pistol != NULL) {

			pistol = new Gun(*(ref.pistol));
		}
		else {

			pistol = NULL;
		}

		handcuffs = ref.handcuffs;
		return *this;
	}

	void PutHandcuff() {

		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot() {

		if (pistol == NULL) {

			cout << "Hut BBANG!" << endl;
		}
		else {

			pistol->Shot();
		}
	}

	~Police() {

		delete pistol;
	}
};

int main(void)
{

	Police pman1(5, 3);
	Police pman2 = pman1;	// ���� �������� ȣ��
	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1;			// ���� �������� ȣ��
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;
}