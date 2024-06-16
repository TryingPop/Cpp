/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 393p

	헤더파일 : NormalAccount 클래스의 선언
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "11_Account.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int ID, int money, const char* name, int rate)
		: Account(ID, money, name), interRate(rate) { }

	virtual void Deposit(int money) {

		Account::Deposit(money);						// 원금 추가
		Account::Deposit(money * (interRate / 100.0));	// 이자 추가
	}
};

#endif