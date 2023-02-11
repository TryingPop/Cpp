/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ� ���� : AccountHandler Ŭ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "05_AccountHandler.h"

using namespace std;

AccountHandler::AccountHandler()
	: accNum(0) { }


void AccountHandler::CreateAccount(Account& acc) {

	int chk = GetAccID(acc.GetAccID());

	if (chk != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�." << endl;
		delete &acc;
		return;
	}

	accArr[accNum++] = &acc;
}

void AccountHandler::DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "����ID: "; cin >> accID;
	cout << "�Աݾ�: "; cin >> money;

	chk = GetAccID(accID);
	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�." << endl;
		return;
	}

	accArr[chk]->Deposit(money);
}

void AccountHandler::WithdrawMoney() {

	int accID;
	int money;
	int chk;

	cout << "����ID: "; cin >> accID;
	cout << "�Աݾ�: "; cin >> money;

	chk = GetAccID(accID);
	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�." << endl;
		return;
	}

	accArr[chk]->Withdraw(money);
}

void AccountHandler::ShowAllInfo() const {

	for (int i = 0; i < accNum; i++) {

		accArr[i]->ShowInfo();
	}
}

int AccountHandler::GetAccID(int ID) {

	for (int i = 0; i < accNum; i++) {

		if(accArr[i]->GetAccID() == ID) {

			return ID;
		}
	}

	return -1;
}

AccountHandler::~AccountHandler() {

	for (int i = 0; i < accNum; i++) {

		delete accArr[i];
	}
}