/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : HAS-A 관계의 다른 표현법
	상속이 아닌 다른 방법으로 표현

	02보다 더 확장성이 더 좋다

	교재 331p 참고에서 IS-A나 HAS-A 이외에는 표현할 생각도 안한다고 한다
	또한, HAS-A도 많이 봐준거라 한다
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
	int handcuffs;	// 소유하고 있는 수갑의 수
	Gun* pistol;	// 소유하고 있는 권총

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

	Police pman2(0, 3);	// 권총을 소유하지 않은 경찰
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}