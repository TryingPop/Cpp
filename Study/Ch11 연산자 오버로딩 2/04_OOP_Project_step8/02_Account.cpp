/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : Account 클래스의 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

#include "01_Account.h"

Account::Account(int ID, const char* name, int money) 
	: accID(ID), balance(money) {

	cusName = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(cusName, name);
}

Account& Account::operator=(const Account& ref) {

	accID = ref.accID;
	delete[] cusName;

	cusName = (char*)malloc(sizeof(char) * (strlen(ref.cusName) + 1));
	strcpy(cusName, ref.cusName);

	balance = ref.balance;

	return *this;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Withdraw(int money) {

	if (balance < money) {

		cout << "잔액이 부족합니다." << endl;
		return;
	}

	balance -= money;
}

void Account::Deposit(int money) {

	balance += money;
}

void Account::ShowInfo() const {

	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}

Account::~Account() {

	delete[] cusName;
}