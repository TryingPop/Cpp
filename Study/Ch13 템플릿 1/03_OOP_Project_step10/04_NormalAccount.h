/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : NormalAccount 클래스의 선언과 정의
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "02_Account.h"
#include "08_myString.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int id, String name, int money, int rate);

	virtual void Deposit(int money);
};

NormalAccount::NormalAccount(int id, String name, int money, int rate)
	: Account(id, name, money), interRate(rate) { }

void NormalAccount::Deposit(int money) {

	Account::Deposit(money);						// 원금추가
	Account::Deposit(money * (interRate / 100.0));	// 이자추가
}
#endif
