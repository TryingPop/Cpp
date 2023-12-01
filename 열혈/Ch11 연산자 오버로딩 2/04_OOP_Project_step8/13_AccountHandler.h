/*
��¥ : 2023. 2. 20
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 496p

	������� : AccountHandler Ŭ������ ����
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "11_Account.h"
#include "14_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray accArr;
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