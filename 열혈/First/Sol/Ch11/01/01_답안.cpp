/*
날짜 : 2023. 2. 21
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Gun {

private:
	int bullet;		// 장전된 총알의 수

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
	}

	Police(const Police& ref)
		: handcuffs(ref.handcuffs) {

		if (ref.pistol != NULL) {

			pistol = new Gun(*ref.pistol);	// Gun의 복사 생성자 호출
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
	Police pman2 = pman1;	// 복사 생성자의 호출
	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1;			// 대입 연산자의 호출
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;
}