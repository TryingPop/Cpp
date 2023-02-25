/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 619p

	�ڵ����� : Account Ŭ������ ����
*/

#include "10_BankingCommonDecl.h"
#include "01_Account.h"
#include "11_AccountException.h"

Account::Account(int ID, int money, String name)
	: accID(ID), balance(money) {

	cusName = name;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	if (money < 0) {

		throw MinusException(money);
	}

	balance += money;
}

int Account::Withdraw(int money) {

	if (money < 0) {

		throw MinusException(money);
	}

	if (balance < money) {

		throw InsuffException(balance, money);
	}

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {

	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}