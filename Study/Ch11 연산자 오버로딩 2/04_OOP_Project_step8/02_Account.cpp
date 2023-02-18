/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : Account Ŭ������ ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

#include "01_Account.h"

Account::Account(int ID, const char* name, int money) 
	: accID(ID), balance(money) {

	cusName = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(cusName, name);
}

Account& Account::operator=(const Account& ref) {

	accID = ref.accID;
	delete[] cusName;

	cusName = (char*)malloc(sizeof(char) * (strlen(ref.cusName) + 1));
	strcpy(cusName, ref.cusName);

	balance = ref.balance;

	return *this;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Withdraw(int money) {

	if (balance < money) {

		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}

	balance -= money;
}

void Account::Deposit(int money) {

	balance += money;
}

void Account::ShowInfo() const {

	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}

Account::~Account() {

	delete[] cusName;
}