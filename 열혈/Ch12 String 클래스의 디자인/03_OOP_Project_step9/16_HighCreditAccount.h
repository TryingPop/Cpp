/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 518p

	헤더파일 : HighCreditAccount 클래스의 선언과 정의
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "15_NormalAccount.h"
#include "18_String.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	// HighCreditAccount(int ID, int money, const char* name, int rate, int special)
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special) { }

	virtual void Deposit(int money) {

		NormalAccount::Deposit(money);						//원금과 이자 추가
		Account::Deposit(money * (specialRate / 100.0));	// 특별 이자 추가
	}
};

#endif
