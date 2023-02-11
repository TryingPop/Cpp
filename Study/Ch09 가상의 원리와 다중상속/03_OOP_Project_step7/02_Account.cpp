/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드 파일 : Account 클래스 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "01_Account.h"

using namespace std;

Account::Account(int ID, const char* name, int money) 
	: accID(ID), balance(money) {

	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

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

void Account::ShowInfo() const {

	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "입금액: " << balance << endl;
	cout << endl;
}

void Account::~Account() {

	delete cusName;
}