/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 518p

	������� : HighCreditAccount Ŭ������ ����� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "15_NormalAccount.h"
#include "18_String.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	// HighCreditAccount(int ID, int money, const char* name, int rate, int special)
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special) { }

	virtual void Deposit(int money) {

		NormalAccount::Deposit(money);						//���ݰ� ���� �߰�
		Account::Deposit(money * (specialRate / 100.0));	// Ư�� ���� �߰�
	}
};

#endif
