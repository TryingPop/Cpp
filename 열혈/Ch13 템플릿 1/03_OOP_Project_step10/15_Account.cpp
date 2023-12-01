/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 517p

	�ڵ����� : Account Ŭ������ ����
*/

#include "14_Account.h"

Account::Account(int ID, int money, String name)
	: accID(ID), balance(money) {

	cusName = name;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	balance += money;
}

int Account::Withdraw(int money) {

	if (balance < money) {

		return 0;
	}

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {

	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}