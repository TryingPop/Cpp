/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : Account 클래스의 선언

	계좌 정보를 담고 있다
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
using namespace std;

class Account {

private:
	int accID;
	int balance;
	char* cusName;


public:
	Account(int ID, const char* name, int money);

	Account& operator=(const Account& ref);

	int GetAccID() const;
	void Withdraw(int money);

	virtual void Deposit(int money);
	void ShowInfo() const;

	~Account();
};

#endif