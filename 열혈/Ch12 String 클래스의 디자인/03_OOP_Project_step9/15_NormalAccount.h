/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 518p

	������� : NormalAccount Ŭ������ ����� ����
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "13_Account.h"
#include "18_String.h"

class NormalAccount : public Account {

private:
	int interRate;	// ������ % ����

public:
	// NormalAccount(int ID, int money, char* name, int rate);
	NormalAccount(int ID, int money, String name, int rate)
		: Account(ID, money, name), interRate(rate) { }

	virtual void Deposit(int money) {

		Account::Deposit(money);						// �����߰�
		Account::Deposit(money * (interRate / 100.0));	// �����߰�
	}
};
#endif