/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : HighCreditAccount Ŭ���� ����� ����
*/

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "03_NormalAccount.h"
#include "09_BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {

private:
	int rank;

public:
	HighCreditAccount(int ID, const char* name, int money, int rate, int rank);

	void Deposit(int money);
	void ShowInfo() const;

	int GetRank() const;
};

inline HighCreditAccount::HighCreditAccount(int ID, const char* name, int money, int rate, int rank)
	: NormalAccount(ID, name, money, rate), rank(rank) { }

void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);	// �Ϲ� ���� + ����
	Account::Deposit((int)((GetRank() * money) / 100.0f));	// �ſ� ��� ����
}

void HighCreditAccount::ShowInfo() const {

	NormalAccount::ShowInfo();
	cout << "�ſ���(1toA, 2toB, 3toC): " << rank << endl;
}

int HighCreditAccount::GetRank() const {

	switch (rank) {

	case 1:
		return LEVEL_A;

	case 2:
		return LEVEL_B;

	case 3:
		return LEVEL_C;

	default:
		return 0;
	}
}
#endif
