/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : Account Ŭ���� ����
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