/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : Account Ŭ������ ����
*/

#include "02_Account.h"

Account::Account(int id, String name, int money)
	: accID(id), cusName(name), balance(money) { }

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	balance += money;
}

void Account::Withdraw(int money) {

	if (balance < money) {

		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}

	balance -= money;
}

void Account::ShowAccInfo() const {

	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}