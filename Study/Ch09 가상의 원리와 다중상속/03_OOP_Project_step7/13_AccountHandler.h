/*
��¥ : 2023. 2. 12
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 394p

	������� : AccountHandler Ŭ���� ����
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "09_Account.h"

class AccountHandler {

private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif