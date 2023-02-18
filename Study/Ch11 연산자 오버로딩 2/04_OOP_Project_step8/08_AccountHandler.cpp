/*
날짜 : 2023. 2. 18
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : AccountHandler 클래스의 정의
*/

#include "01_Account.h"
#include "04_HighCreditAccount.h"
#include "07_AccountHandler.h"
#include "09_BankingCommonDecl.h"

AccountHandler::AccountHandler(int len)
	: accArr(len), accNum(0), choice(0) { }

void AccountHandler::CreateAccount() {
	int choiceCreate;

	cout << "[계좌종류 선택]" << endl;
	cout << "1. 보통예금계좌 ";
	cout << "2. 신용신뢰계좌" << endl;
	cout << "선택: "; cin >> choiceCreate;

	if (choiceCreate == NORMAL) {

		CreateNormal();
	}
	else if (choiceCreate == HIGHCREDIT) {

		CreateHighCredit();
	}
	else {

		cout << "잘못된 입력을 하였습니다." << endl;
	}
}

void AccountHandler::DepositMoney() {

	int accID;
	int money;

	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> accID;
	cout << "입금액: "; cin >> money;

	accArr[accID]->Deposit(money);
}


void AccountHandler::WithdrawMoney() {

	int accID;
	int money;

	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> accID;
	cout << "출금액: "; cin >> money;

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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: "; cin >> choice;

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
		cout << "프로그램 종료" << endl;
		break;

	default:
		cout << "잘못된 입력을 하였습니다." << endl;
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

	cout << "[보통예금계좌 개설]" << endl;
	cout << "1. 계좌ID: "; cin >> id;
	cout << "2. 이  름: "; cin >> name;
	cout << "3. 입금액: "; cin >> money;
	cout << "4. 이자율: "; cin >> rate;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccID() == id) {

			cout << "이미 존재하는 꼐좌ID 입니다" << endl;
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

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "1. 계좌ID: "; cin >> id;
	cout << "2. 이  름: "; cin >> name;
	cout << "3. 입금액: "; cin >> money;
	cout << "4. 이자율: "; cin >> rate;
	cout << "5. 신용등급(1toA, 2toB, 3toC): "; cin >> rank;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccID() == id) {

			cout << "이미 존재하는 꼐좌ID 입니다" << endl;
			return;
		}
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, rate, rank);
}