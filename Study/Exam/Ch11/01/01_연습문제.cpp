/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 교재 452p 문제1
	Chapter 07에서는 예제 HASComposite.cpp(교재 309p)에서 다음의 두 클래스를 정의하였다.
	class Gun {
		
	private:
		int bullet;	// 장전된 총알의 수

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
		int handcuffs;	// 소유한 수갑의 수
		Gun* pistol;	// 소유하고 있는 권총
		
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

	이에 Police 클래스를 대상으로 깊은 복사가 이뤄지도록
	대립 연산자와 복사 생성자를 동시에 정의하고
	이의 확인을 위한 main 함수도 적절히 정의해보자.
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