/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : AccountHandler Ŭ������ ����
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "06_HighCreditAccount.h"
#include "07_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray acc;
	int accNum;
	int choice;

public:
	AccountHandler();

	void Start();			// ���α׷� ����

	void ShowMenu();	// ��� ����
	void SelectOpt();		// ��ɿ� ���� �ൿ ����

	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	
	int ChkAccID(int id);	// �ߺ� ���� Ȯ��

protected:
	void CreateNormal();
	void CreateHighCredit();
};

#endif