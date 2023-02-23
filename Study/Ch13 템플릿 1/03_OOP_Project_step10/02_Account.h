/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : Account Ŭ������ ����
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
