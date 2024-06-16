/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : AccountHandler Ŭ������ ����
*/

#include "01_BoundCheckArray.h"
#include "02_Account.h"
#include "04_NormalAccount.h"
#include "05_HighCreditAccount.h"
#include "06_AccountHandler.h"
#include "08_myString.h"
#include "10_BankingCommonDecl.h"

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
	cout << "2. ��  ��" << endl;
	cout << "3. ��  ��" << endl;
	cout << "4. �������� ��ü ��ȸ" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: "; cin >> choice;
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
		cout << "���α׷� ����";
		break;

	default:
		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
	}

	cout << endl;
}

void AccountHandler::CreateAccount() {

	int sel;

	cout << "[���°���]" << endl;
	cout << "1. ���뿹�ݰ��� ";
	cout << "2. �ſ�ŷڰ��� " << endl;
	cout << "����: "; cin >> sel;

	if (sel == NORMAL) {

		CreateNormalAccount();
	}
	else if (sel == HIGHCREDIT) {

		CreateHighCreditAccount();
	}
	else {

		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
	}
}

void AccountHandler::CreateNormalAccount() {

	int id;
	String name;
	int money;
	int rate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> rate;

	if (GetAccIdx(id) != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	accArr[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::CreateHighCreditAccount() {

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

	if (GetAccIdx(id) != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, rate, special);
}

void AccountHandler::DepositMoney() {

	int id;
	int money;
	int chk;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;
	
	chk = GetAccIdx(id);

	if (chk == -1) {

		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	accArr[chk]->Deposit(money);
}

void AccountHandler::WithdrawMoney() {

	int id;
	int money;
	int chk;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	chk = GetAccIdx(id);

	if (chk == -1) {

		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	accArr[chk]->Withdraw(money);
}

void AccountHandler::ShowAllAccInfo() const {

	for (int idx = 0; idx < accNum; idx++) {

		accArr[idx]->ShowAccInfo();
		cout << endl;
	}
}

int AccountHandler::GetAccIdx(int id) const {

	for (int idx = 0; idx < accNum; idx++) {

		if (id == accArr[idx]->GetAccID()) {

			return idx;
		}
	}

	return -1;
}