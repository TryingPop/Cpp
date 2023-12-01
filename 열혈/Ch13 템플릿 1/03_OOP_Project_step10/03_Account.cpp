/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : Account 클래스의 정의
*/

#include "02_Account.h"

Account::Account(int id, String name, int money)
	: accID(id), cusName(name), balance(money) { }

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	balance += money;
}

void Account::Withdraw(int money) {

	if (balance < money) {

		cout << "잔액이 부족합니다." << endl;
		return;
	}

	balance -= money;
}

void Account::ShowAccInfo() const {

	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}