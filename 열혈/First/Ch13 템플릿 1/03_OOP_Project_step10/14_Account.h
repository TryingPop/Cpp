/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 516p

	������� : Account Ŭ������ ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "19_String.h"

class Account {

private:
	int accID;
	int balance;
	String cusName;

public:
	Account(int ID, int money, String name);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};

#endif
