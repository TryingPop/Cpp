/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드 파일 : AccountHandler 클래스 정의
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

		cout << "이미 존재하는 계좌번호입니다." << endl;
		delete &acc;
		return;
	}

	accArr[accNum++] = &acc;
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