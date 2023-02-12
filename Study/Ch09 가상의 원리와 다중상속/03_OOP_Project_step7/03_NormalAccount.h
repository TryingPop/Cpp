/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : NormalAccount Ŭ���� ����� ����
*/

#ifndef __NORMAL_H_
#define __NORMAL_H_

#define _CRT_SECURE_NO_WARNINGS
#include "01_Account.h"
#include "07_BankingCommonDecl.h"

class NormalAccount : public Account {

private:
	int interRate;	// ������

public:
	NormalAccount(int ID, const char* name, int money, int inter);

	virtual void Deposit(int money);
	void ShowInfo() const;
};

// �ζ����� �����ٰ� �ϰ� ����̹Ƿ� �ζ������� ����
inline NormalAccount::NormalAccount(int ID, const char* name, int money, int inter)
	: Account(ID, name, money), interRate(inter) { }

inline void NormalAccount::Deposit(int money) {

	money += (int)((interRate * money) / 100.0f);
	Account::Deposit(money);
}

inline void NormalAccount::ShowInfo() const {

	Account::ShowInfo();
	cout << "������: " << interRate << endl;
}

#endif
