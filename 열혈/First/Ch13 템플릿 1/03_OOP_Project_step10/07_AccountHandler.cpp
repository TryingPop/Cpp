/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : AccountHandler 클래스의 정의
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금" << endl;
	cout << "4. 계좌정보 전체 조회" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: "; cin >> choice;
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
		cout << "프로그램 종료";
		break;

	default:
		cout << "잘못된 입력을 하였습니다." << endl;
	}

	cout << endl;
}

void AccountHandler::CreateAccount() {

	int sel;

	cout << "[계좌개설]" << endl;
	cout << "1. 보통예금계좌 ";
	cout << "2. 신용신뢰계좌 " << endl;
	cout << "선택: "; cin >> sel;

	if (sel == NORMAL) {

		CreateNormalAccount();
	}
	else if (sel == HIGHCREDIT) {

		CreateHighCreditAccount();
	}
	else {

		cout << "잘못된 입력을 하였습니다." << endl;
	}
}

void AccountHandler::CreateNormalAccount() {

	int id;
	String name;
	int money;
	int rate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> rate;

	if (GetAccIdx(id) != -1) {

		cout << "이미 존재하는 계좌번호입니다." << endl;
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

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> rate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> special;

	if (GetAccIdx(id) != -1) {

		cout << "이미 존재하는 계좌번호입니다." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, rate, special);
}

void AccountHandler::DepositMoney() {

	int id;
	int money;
	int chk;

	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;
	
	chk = GetAccIdx(id);

	if (chk == -1) {

		cout << "존재하지 않는 계좌입니다." << endl;
		return;
	}

	accArr[chk]->Deposit(money);
}

void AccountHandler::WithdrawMoney() {

	int id;
	int money;
	int chk;

	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	chk = GetAccIdx(id);

	if (chk == -1) {

		cout << "존재하지 않는 계좌입니다." << endl;
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