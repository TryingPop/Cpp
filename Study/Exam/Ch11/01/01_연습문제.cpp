/*
��¥ : 2023. 2. 20
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

#include <iostream>
using namespace std;

class Gun {

private:
	int bullet;

public:
	Gun(int bnum)
		: bullet(bnum) { }

	Gun(const Gun& ref) 
		: bullet(ref.bullet) { }

	void Shot() {

		cout << "BBANG!" << endl;
		bullet--;
	}

	void GunInfo() {

		cout << "bullet : " << bullet << endl;
	}
};

class Police {

private:
	int handcuffs;
	Gun* pistol;

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

		if (ref.pistol == NULL) {

			pistol == NULL;
		}
		else {

			pistol = new Gun(*ref.pistol);
		}
	}

	Police& operator=(const Police ref) {

		if (pistol != NULL) {

			delete pistol;
		}

		handcuffs = ref.handcuffs;
		pistol = new Gun(*ref.pistol);

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

	void ShowInfo() {

		if (pistol != NULL) {
			pistol->GunInfo();
		}
		else {
			cout << "gun : not exist" << endl;
		}
		cout << "handcuffs : " << handcuffs << endl;
		cout << endl;
	}

	~Police() {

		cout << "fire" << endl;

		if (pistol != NULL) {

			delete pistol;
		}
	}
};

int main(void)
{

	Police A(2, 3);
	Police B = A;
	Police C(0, 0);

	
	B.Shot();
	B.PutHandcuff();

	C = B;

	B.Shot();
	B.PutHandcuff();

	cout << 'A' << endl;
	A.ShowInfo();

	cout << 'B' << endl;
	B.ShowInfo();

	cout << 'C' << endl;
	C.ShowInfo();

	return 0;
}