/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 393p

	헤더파일 : HighCreditAccount 클래스의 선언
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "16_NormalAccount.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int ID, int money, const char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special) { }

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);						// 원금과 이자 추가
		Account::Deposit(money * (specialRate / 100.0));	// 특별이자 추가
	}
};

#endif