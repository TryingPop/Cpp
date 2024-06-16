/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 620p

	헤더파일 : NormalAccount 클래스의 선언과 정의
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "01_Account.h"
#include "08_String.h"
#include "11_AccountException.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int ID, int money, String name, int rate)
		: Account(ID, money, name), interRate(rate) { }

	virtual void Deposit(int money) {

		if (money < 0) {

			throw MinusException(money);
		}

		Account::Deposit(money);						// 원금추가
		Account::Deposit(money * (interRate / 100.0));	// 이자추가
	}
};

#endif
