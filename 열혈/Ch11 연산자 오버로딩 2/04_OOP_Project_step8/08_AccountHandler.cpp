/*
��¥ : 2023. 2. 18
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : AccountHandler Ŭ������ ����
*/

#include "01_Account.h"
#include "04_HighCreditAccount.h"
#include "07_AccountHandler.h"
#include "09_BankingCommonDecl.h"

AccountHandler::AccountHandler(int len)
	: accArr(len), accNum(0), choice(0) { }

void AccountHandler::CreateAccount() {
	int choiceCreate;

	cout << "[�������� ����]" << endl;
	cout << "1. ���뿹�ݰ��� ";
	cout << "2. �ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> choiceCreate;

	if (choiceCreate == NORMAL) {

		CreateNormal();
	}
	else if (choiceCreate == HIGHCREDIT) {

		CreateHighCredit();
	}
	else {

		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
	}
}

void AccountHandler::DepositMoney() {

	int accID;
	int money;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> accID;
	cout << "�Աݾ�: "; cin >> money;

	accArr[accID]->Deposit(money);
}


void AccountHandler::WithdrawMoney() {

	int accID;
	int money;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> accID;
	cout << "��ݾ�: "; cin >> money;

	accArr[accID]->Withdraw(money);
}

void AccountHandler::ShowAllInfo() const {

	for (int idx = 0; idx < accNum; idx++) {

		accArr[idx]->ShowInfo();
		cout << endl;
	}
}

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
		ShowAllInfo();
		break;

	case EXIT:
		cout << "���α׷� ����" << endl;
		break;

	default:
		cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
		break;
	}
	cout << endl;
}

AccountHandler::~AccountHandler() {

	delete[]& accArr;
}

void AccountHandler::CreateNormal() {

	int id;
	char name[30];
	int money;
	int rate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "1. ����ID: "; cin >> id;
	cout << "2. ��  ��: "; cin >> name;
	cout << "3. �Աݾ�: "; cin >> money;
	cout << "4. ������: "; cin >> rate;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccID() == id) {

			cout << "�̹� �����ϴ� ����ID �Դϴ�" << endl;
			return;
		}
	}

	accArr[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::CreateHighCredit() {

	int id;
	char name[30];
	int money;
	int rate;
	int rank;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "1. ����ID: "; cin >> id;
	cout << "2. ��  ��: "; cin >> name;
	cout << "3. �Աݾ�: "; cin >> money;
	cout << "4. ������: "; cin >> rate;
	cout << "5. �ſ���(1toA, 2toB, 3toC): "; cin >> rank;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccID() == id) {

			cout << "�̹� �����ϴ� ����ID �Դϴ�" << endl;
			return;
		}
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, rate, rank);
}