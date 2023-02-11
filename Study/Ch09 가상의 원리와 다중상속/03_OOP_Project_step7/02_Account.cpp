/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ� ���� : Account Ŭ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "01_Account.h"

using namespace std;

Account::Account(int ID, const char* name, int money) 
	: accID(ID), balance(money) {

	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

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
	cout << "�Աݾ�: " << balance << endl;
	cout << endl;
}

void Account::~Account() {

	delete cusName;
}