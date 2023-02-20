/*
��¥ : 2023. 2. 20
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 393p

	������� : NormalAccount Ŭ������ ����
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

		Account::Deposit(money);						// ���� �߰�
		Account::Deposit(money * (interRate / 100.0));	// ���� �߰�
	}
};

#endif