/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : NormalAccount Ŭ������ ����� ����
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

	Account::Deposit(money);						// �����߰�
	Account::Deposit(money * (interRate / 100.0));	// �����߰�
}
#endif
