/*
��¥ : 2023. 2. 18
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : AccountHandler Ŭ������ ����
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "05_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray accArr;
	int accNum;
	int choice;

public:
	AccountHandler(int len);

	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllInfo() const;

	void Start();

	void ShowMenu();
	void SelectOpt();

	~AccountHandler();

protected:
	void CreateNormal();
	void CreateHighCredit();
};

#endif
