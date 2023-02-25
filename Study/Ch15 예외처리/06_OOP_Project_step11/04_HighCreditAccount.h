/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 621p

	������� : HighCreditAccount Ŭ������ ����� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "03_NormalAccount.h"
#include "08_String.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special) { }

	virtual void Deposit(int money) {

		if (money < 0) {

			throw MinusException(money);
		}

		NormalAccount::Deposit(money);						// ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0));	// Ư�������߰�
	}
};

#endif
