/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : HighCreditAccount 클래스의 선언과 정의
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "05_NormalAccount.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int id, String name, int money, int rate, int special);

	void Deposit(int money);
};

inline HighCreditAccount::HighCreditAccount(int id, String name, int money, int rate, int special)
	: NormalAccount(id, name, money, rate), specialRate(special) { }

inline void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	
	int rate;

	// rate 값 대입하는거 RANK_A, RANK_B, RANK_C로 변경하기!
	switch (specialRate) {

	case 1:
		rate = RANK_A;
		break;
	case 2:
		rate = RANK_B;
		break;
	case 3:
		rate = RANK_C;
		break;
	default:
		rate = 0;
		break;
	}
	cout << rate << endl;
	Account::Deposit((int)((money * rate) / 100.0));
}

#endif