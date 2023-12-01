/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 620p

	������� : NormalAccount Ŭ������ ����� ����
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "01_Account.h"
#include "08_String.h"
#include "11_AccountException.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int ID, int money, String name, int rate)
		: Account(ID, money, name), interRate(rate) { }

	virtual void Deposit(int money) {

		if (money < 0) {

			throw MinusException(money);
		}

		Account::Deposit(money);						// �����߰�
		Account::Deposit(money * (interRate / 100.0));	// �����߰�
	}
};

#endif
