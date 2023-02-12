/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ� ���� : AccountHandler Ŭ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include "01_Account.h"
#include "03_NormalAccount.h"
#include "04_HighCreditAccount.h"
#include "05_AccountHandler.h"
#include "07_BankingCommonDecl.h"

AccountHandler::AccountHandler()
	: accNum(0), choice(0) { }


void AccountHandler::CreateAccount() {

	int select;

	cout << "[�������� ����]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> select;

	if (select == SELECT_ACC::NORMAL) {

		CreateNormal();
	}
	else if (select == SELECT_ACC::HIGHCREDIT) {

		CreateHighCredit();
	}
	else {

		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
	}
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

	cout << "[�������� ��ü ���]" << endl;
	for (int i = 0; i < accNum; i++) {

		accArr[i]->ShowInfo();
		cout << endl;
	}
}

void AccountHandler::Start() {

	while (choice != 5) {

		ShowMenu();
		SelectOpt();
	}
	cout << "���α׷� ����" << endl;
}

void AccountHandler::ShowMenu() {

	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: "; cin >> choice;
}

void AccountHandler::SelectOpt() {

	switch (choice) {

	case SELECT_OPT::CREATE:
		CreateAccount();
		break;

	case SELECT_OPT::DEPOSIT:
		DepositMoney();
		break;

	case SELECT_OPT::WITHDRAW:
		WithdrawMoney();
		break;

	case SELECT_OPT::INQUIRE:
		ShowAllInfo();
		break;
		
	case SELECT_OPT::EXIT:
		break;

	default:
		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
		break;
	}

	cout << endl;
}

int AccountHandler::GetAccID(int ID) {

	for (int i = 0; i < accNum; i++) {

		if(accArr[i]->GetAccID() == ID) {

			return i;
		}
	}

	return -1;
}

void AccountHandler::CreateNormal() {

	int id;
	char name[30];
	int money;
	int inter;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "1. ����ID: "; cin >> id;
	cout << "2. ��  ��: "; cin >> name;
	cout << "3. �Աݾ�: "; cin >> money;
	cout << "4. ������: "; cin >> inter;

	if (GetAccID(id) != -1) {

		cout << "�̹� �����ϴ� �����Դϴ�." << endl;
		return;
	}

	accArr[accNum++] = new NormalAccount(id, name, money, inter);
}

void AccountHandler::CreateHighCredit() {

	int id;
	char name[30];
	int money;
	int inter;
	int rank;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "1. ����ID: "; cin >> id;
	cout << "2. ��  ��: "; cin >> name;
	cout << "3. �Աݾ�: "; cin >> money;
	cout << "4. ������: "; cin >> inter;
	cout << "5. �ſ���(1toA, 2toB, 3toC): "; cin >> rank;

	if (GetAccID(id) != -1) {

		cout << "�̹� �����ϴ� �����Դϴ�." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, inter, rank);
}

AccountHandler::~AccountHandler() {

	for (int i = 0; i < accNum; i++) {

		delete accArr[i];
	}
}