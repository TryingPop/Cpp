/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� ���� ���Ϸ� ����� �ڵ带 ����

	������� : Account Ŭ������ ����
*/

#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

class Account {

private:
	int accID;
	char* cusName;
	int balance;

public:
	Account(int ID, const char* name, int money);
	
	int GetAccID() const;
	void Withdraw(int money);
	virtual void Deposit(int money);
	virtual void ShowInfo() const = 0;

	~Account();
};
#endif