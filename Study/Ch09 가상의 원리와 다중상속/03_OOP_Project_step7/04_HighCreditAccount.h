/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	��� ���� : HighCreditAccount Ŭ���� ����� ����
*/

#ifndef __HIGHCREDIT_H_
#define __HIGHCREDIT_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "03_NormalAccount.h"
using namespace std;

namespace RANK {
	enum {A, B, C};

	int GetInter(int rank) {

		switch (rank) {

		case 1:
			return A;

		case 2:
			return B;

		case 3:
			return C;

		default:
			return 0;
		}
	}
}

class HighCreditAccount : public NormalAccount {

private:
	int rank;

public:
	HighCreditAccount(int ID, const char* name, int money, int inter, int rank);

	void Deposit(int money);
	void ShowInfo() const;

	int GetRankInter(int money);
};

inline HighCreditAccount::HighCreditAccount(int ID, const char* name, int money, int inter, int rank)
	: NormalAccount(ID, name, money, inter), rank(rank) { }

inline void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	Account::Deposit(GetRankInter(money));
}

inline void HighCreditAccount::ShowInfo() const {

	NormalAccount::ShowInfo();
	cout << "�ſ���(1toA, 2toB, 3toC): " << rank << endl;
}

inline int HighCreditAccount::GetRankInter(int money) {

	return money * RANK::GetInter(rank);
}
#endif
