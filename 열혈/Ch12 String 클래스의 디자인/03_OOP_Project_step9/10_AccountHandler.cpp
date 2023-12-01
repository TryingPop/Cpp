/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : AccountHandler Ŭ������ ����
*/

#include "01_myString.h"
#include "03_Account.h"
#include "05_NormalAccount.h"
#include "06_HighCreditAccount.h"
#include "07_AccountArray.h"
#include "09_AccountHandler.h"
#include "11_BankingCommonDecl.h"

AccountHandler::AccountHandler()
	: accNum(0), choice(0) { }

void AccountHandler::Start() {

	while (choice != 5) {

		ShowMenu();
		SelectOpt();
	}
}

void AccountHandler::ShowMenu() {

	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: "; cin >> choice;
	cout << endl;
}

void AccountHandler::SelectOpt() {

	switch (choice) {

	case CREATE:
		CreateAccount();
		break;
		
	case DEPOSIT:
		DepositMoney();
		break;

	case WITHDRAW:
		WithdrawMoney();
		break;

	case INQUIRE:
		ShowAllAccInfo();
		break;

	case EXIT:
		cout << "���α׷� ����" << endl;
		break;

	default:
		cout << "�߸��� �Է��� �Ͽ����ϴ�" << endl;
		break;
	}

	cout << endl;
}

void AccountHandler::CreateAccount() {

	int sel;

	cout << "[���°���]" << endl;
	cout << "1. ���뿹�ݰ��� ";
	cout << "2. �ſ�ŷڰ��� " << endl;
	cout << "����: "; cin >> sel;

	// Normal, HighCredit���� ��ü
	if (sel == NORMAL) {

		CreateNormal();
	}
	else if (sel == HIGHCREDIT) {

		CreateHighCredit();
	}
	else {

		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
	}
}

void AccountHandler::CreateNormal() {

	int id;
	String name;
	int money;
	int rate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> rate;
	
	if (ChkAccID(id) != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	acc[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::CreateHighCredit() {

	int id;
	String name;
	int money;
	int rate;
	int special;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> rate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> special;

	if (ChkAccID(id) != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	acc[accNum++] = new HighCreditAccount(id, name, money, rate, special);
}


int AccountHandler::ChkAccID(int id) {

	for (int i = 0; i < accNum; i++) {

		if (id == acc[i]->GetAccID()) {

			return i;
		}
	}

	return -1;
}

void AccountHandler::DepositMoney() {

	int id;
	int money;
	int chk;

	cout << "[��  ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	chk = ChkAccID(id);

	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	acc[chk]->Deposit(money);
}

void AccountHandler::WithdrawMoney() {

	int id;
	int money;
	int chk;

	cout << "[��  ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;
	
	chk = ChkAccID(id);

	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	acc[chk]->Withdraw(money);
}

void AccountHandler::ShowAllAccInfo() const {

	for (int idx = 0; idx < accNum; idx++) {

		acc[idx]->ShowInfo();
		cout << endl;
	}
}