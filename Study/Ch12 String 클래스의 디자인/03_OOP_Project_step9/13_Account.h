/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 516p

	������� : Account Ŭ������ ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "18_String.h"

class Account {

private:
	int accID;
	int balance;
	String cusName;	// char* cusName;

public:
	Account(int ID, int money, String name);
	// Account(int ID, int money, const char* name);

	// Account(const Account& ref);
	// Account& operator=(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	// ~Account();
};

#endif
