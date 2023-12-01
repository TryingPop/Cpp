/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드 파일 : AccountHandler 클래스 정의
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

	cout << "[계좌종류 선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: "; cin >> select;

	if (select == SELECT_ACC::NORMAL) {

		CreateNormal();
	}
	else if (select == SELECT_ACC::HIGHCREDIT) {

		CreateHighCredit();
	}
	else {

		cout << "잘못된 입력을 하였습니다." << endl;
	}
}

void AccountHandler::DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "계좌ID: "; cin >> accID;
	cout << "입금액: "; cin >> money;

	chk = GetAccID(accID);
	if (chk == -1) {

		cout << "존재하지 않는 계좌번호 입니다." << endl;
		return;
	}

	accArr[chk]->Deposit(money);
}

void AccountHandler::WithdrawMoney() {

	int accID;
	int money;
	int chk;

	cout << "계좌ID: "; cin >> accID;
	cout << "입금액: "; cin >> money;

	chk = GetAccID(accID);
	if (chk == -1) {

		cout << "존재하지 않는 계좌번호 입니다." << endl;
		return;
	}

	accArr[chk]->Withdraw(money);
}

void AccountHandler::ShowAllInfo() const {

	cout << "[계좌정보 전체 출력]" << endl;
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
	cout << "프로그램 종료" << endl;
}

void AccountHandler::ShowMenu() {

	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: "; cin >> choice;
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
		cout << "잘못된 입력을 하였습니다." << endl;
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

	cout << "[보통예금계좌 개설]" << endl;
	cout << "1. 계좌ID: "; cin >> id;
	cout << "2. 이  름: "; cin >> name;
	cout << "3. 입금액: "; cin >> money;
	cout << "4. 이자율: "; cin >> inter;

	if (GetAccID(id) != -1) {

		cout << "이미 존재하는 계좌입니다." << endl;
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

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "1. 계좌ID: "; cin >> id;
	cout << "2. 이  름: "; cin >> name;
	cout << "3. 입금액: "; cin >> money;
	cout << "4. 이자율: "; cin >> inter;
	cout << "5. 신용등급(1toA, 2toB, 3toC): "; cin >> rank;

	if (GetAccID(id) != -1) {

		cout << "이미 존재하는 계좌입니다." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, inter, rank);
}

AccountHandler::~AccountHandler() {

	for (int i = 0; i < accNum; i++) {

		delete accArr[i];
	}
}