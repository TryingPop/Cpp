/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 555p

	������� : AccountHandler Ŭ������ ����
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "14_Account.h"
#include "12_BoundCheckArray.h"

class AccountHandler {

private:
	BoundCheckArray<Account*> accArr;
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