/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	��� ���� : AccountHandler Ŭ���� ����
*/

#ifndef __ACCHANDLER_H_
#define __ACCHANDLER_H_

#define _CRT_SECURE_NO_WARNINGS
#include "01_Account.h"

class AccountHandler {

private:
	Account* accArr[100];
	int accNum;
	int choice;

public:
	AccountHandler();

	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllInfo() const;

	void Start();

	void ShowMenu();
	void SelectOpt();

	int GetAccID(int ID);

	void CreateNormal();
	void CreateHighCredit();

	~AccountHandler();
};

#endif
