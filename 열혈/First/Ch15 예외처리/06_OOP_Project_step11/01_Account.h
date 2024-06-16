/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 619p

	헤더파일 : Account 클래스의 선언
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "08_String.h"

class Account {

private:
	int accID;
	int balance;
	String cusName;		// char* cusName;

public:
	Account(int ID, int money, String name);
	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};

#endif