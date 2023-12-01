/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : NormalAccount Ŭ������ ����� ����
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "03_Account.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int id, String name, int money, int rate);
	
	void Deposit(int money);
};

inline NormalAccount::NormalAccount(int id, String name, int money, int rate) 
	: Account(id, name, money), interRate(rate) { }

inline void NormalAccount::Deposit(int money) {

	Account::Deposit(money);	// ���� �߰�
	Account::Deposit((int)((money * interRate) / 100.0));	// ���� �߰�
}

#endif