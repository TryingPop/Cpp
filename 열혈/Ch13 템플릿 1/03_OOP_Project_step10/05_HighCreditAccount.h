/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : HighCreditAccount Ŭ������ ����� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "04_NormalAccount.h"
#include "08_myString.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int id, String name, int money, int rate, int special);

	virtual void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int id, String name, int money, int rate, int special)
	: NormalAccount(id, name, money, rate), specialRate(special) { }

void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	int rate;

	// �� ���� �ʼ�!
	switch (specialRate) {

	case 1:
		rate = LEVEL_A;
		break;

	case 2:
		rate = LEVEL_B;
		break;

	case 3:
		rate = LEVEL_C;
		break;

	default:
		rate = 0;
	}

	
	Account::Deposit(money * (rate / 100.0));
}
#endif
