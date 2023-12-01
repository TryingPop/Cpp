/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 495p
	
	코드파일 : Account 클래스의 정의
*/

#include "19_BankingCommonDecl.h"
#include "11_Account.h"

Account::Account(int ID, int money, const char* name) 
	: accID(ID), balance(money) {

	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) {

	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref) {	// 추가된 정의

	accID = ref.accID;
	balance = ref.balance;
	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);

	return *this;
}

int Account::GetAccID() const {

	return accID;
}

void Account::Deposit(int money) {

	balance += money;
}

int Account::Withdraw(int money) {

	if (balance < money) {

		return 0;
	}

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {

	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}

Account::~Account() {

	delete[] cusName;
}