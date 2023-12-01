/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 240p
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define NAME_LEN	20
using namespace std;

class Account {

private:
	int accID;		// 계좌번호
	int balance;	// 잔    액
	char* cusName;	// 고객이름

public:
	Account(int ID, int money, char* name) 
		: accID(ID), balance(money) {

		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& ref) 
		: accID(ref.accID), balance(ref.balance) {

		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	int GetAccID() { return accID; }

	void Deposit(int money) {

		balance += money;
	}

	int Withdraw(int money) {

		if (balance < money) {

			return 0;
		}

		balance -= money;
		return money;
	}

	void ShowAccInfo() {

		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << cusName << endl;
		cout << "잔  액: " << balance << endl;
	}

	~Account() {

		delete[] cusName;
	}
};