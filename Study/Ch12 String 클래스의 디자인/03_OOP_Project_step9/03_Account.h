/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : Account 클래스 선언
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "01_myString.h"
#include "11_BankingCommonDecl.h"

class Account {

private:
	int accID;
	int balance;
	String cusName;

public:
	Account(int id, String name, int money);
	Account(const Account& ref);

	int GetAccID() const;
	void ShowInfo() const;

	virtual void Deposit(int money);
	void Withdraw(int money);
};
#endif