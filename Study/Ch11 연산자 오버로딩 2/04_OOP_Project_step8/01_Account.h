/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : Account Ŭ������ ����

	���� ������ ��� �ִ�
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
using namespace std;

class Account {

private:
	int accID;
	int balance;
	char* cusName;


public:
	Account(int ID, const char* name, int money);

	Account& operator=(const Account& ref);

	int GetAccID() const;
	void Withdraw(int money);

	virtual void Deposit(int money);
	void ShowInfo() const;

	~Account();
};

#endif