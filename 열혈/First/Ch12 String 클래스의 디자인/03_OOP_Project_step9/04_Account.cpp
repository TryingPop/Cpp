/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : Account Ŭ������ ����
*/

#include "03_Account.h"

Account::Account(int id, String name, int money)
	: accID(id), balance(money), cusName(name) { }


Account::Account(const Account& ref) 
	: accID(ref.accID), balance(ref.balance), cusName(ref.cusName) { }

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

void Account::ShowInfo() const {

	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}