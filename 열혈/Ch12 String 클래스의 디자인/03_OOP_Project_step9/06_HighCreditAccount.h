/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : HighCreditAccount Ŭ������ ����� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "05_NormalAccount.h"

class HighCreditAccount : public NormalAccount {

private:
	int specialRate;

public:
	HighCreditAccount(int id, String name, int money, int rate, int special);

	void Deposit(int money);
};

inline HighCreditAccount::HighCreditAccount(int id, String name, int money, int rate, int special)
	: NormalAccount(id, name, money, rate), specialRate(special) { }

inline void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	
	int rate;

	// rate �� �����ϴ°� RANK_A, RANK_B, RANK_C�� �����ϱ�!
	switch (specialRate) {

	case 1:
		rate = RANK_A;
		break;
	case 2:
		rate = RANK_B;
		break;
	case 3:
		rate = RANK_C;
		break;
	default:
		rate = 0;
		break;
	}
	cout << rate << endl;
	Account::Deposit((int)((money * rate) / 100.0));
}

#endif