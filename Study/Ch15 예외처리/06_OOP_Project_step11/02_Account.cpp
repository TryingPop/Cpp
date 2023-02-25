/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 619p

	코드파일 : Account 클래스의 정의
*/

#include "10_BankingCommonDecl.h"
#include "01_Account.h"
#include "11_AccountException.h"

Account::Account(int ID, int money, String name)
	: accID(ID), balance(money) {

	cusName = name;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	if (money < 0) {

		throw MinusException(money);
	}

	balance += money;
}

int Account::Withdraw(int money) {

	if (money < 0) {

		throw MinusException(money);
	}

	if (balance < money) {

		throw InsuffException(balance, money);
	}

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {

	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}