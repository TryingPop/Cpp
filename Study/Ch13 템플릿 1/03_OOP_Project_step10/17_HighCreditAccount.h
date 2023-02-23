/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 518p

	������� : HighCreditAccount Ŭ������ ����� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "16_NormalAccount.h"
#include "19_String.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special){ }

	virtual void Deposit(int money) {

		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));	// Ư�� �����߰�
	}
};

#endif
