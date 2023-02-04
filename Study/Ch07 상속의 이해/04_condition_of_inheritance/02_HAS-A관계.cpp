/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : HAS-A 관계도
	상속의 조건은 되지만 복합 관계로 이를 대신하는 것이 일반적

	has a = ~을 소유한다
		경찰 has a 총
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

class Police : public Gun {

private:
	int handcuffs;	// 소유한 수갑의 수

public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff) { }

	void PutHandcuff() {

		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void) 
{

	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}