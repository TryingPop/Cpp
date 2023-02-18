/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : NormalAccount Ŭ���� ����� ����
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "01_Account.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int ID, const char* name, int money, int rate);

	void Deposit(int money);
	void ShowInfo() const;
};

inline NormalAccount::NormalAccount(int ID, const char* name, int money, int rate)
	: Account (ID, name, money), interRate(rate) { }

inline void NormalAccount::Deposit(int money) {

	Account::Deposit(money);	// ����
	Account::Deposit((int)((money * interRate) / 100.0f));	// ����
}

inline void NormalAccount::ShowInfo() const {

	Account:ShowInfo();
	cout << "������: " << interRate << endl;
} 
#endif
