/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : Account 클래스의 선언
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "08_myString.h"
#include "10_BankingCommonDecl.h"

class Account {

private:
	int accID;
	String cusName;
	int balance;

public:
	Account(int id, String name, int money);

	int GetAccID() const;

	virtual void Deposit(int money);

	void Withdraw(int money);
	void ShowAccInfo() const;
};

#endif
