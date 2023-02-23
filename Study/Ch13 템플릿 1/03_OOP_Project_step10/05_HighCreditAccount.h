/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : HighCreditAccount 클래스의 선언과 정의
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "04_NormalAccount.h"
#include "08_myString.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int id, String name, int money, int rate, int special);

	virtual void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int id, String name, int money, int rate, int special)
	: NormalAccount(id, name, money, rate), specialRate(special) { }

void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	int rate;

	// 값 변경 필수!
	switch (specialRate) {

	case 1:
		rate = LEVEL_A;
		break;

	case 2:
		rate = LEVEL_B;
		break;

	case 3:
		rate = LEVEL_C;
		break;

	default:
		rate = 0;
	}

	
	Account::Deposit(money * (rate / 100.0));
}
#endif
