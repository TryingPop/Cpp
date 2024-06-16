/*
��¥ : 2023. 2. 3
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 267p
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Account {

private:
	int accID;		// ���¹�ȣ
	int balance;	// ��    ��
	char* cusName;	// ���̸�

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

	int GetAccID() const { return accID; }

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

	void ShowAccInfo() const {
		cout << "����ID: " << accID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� ��: " << balance << endl;
	}

	~Account() {

		delete[] cusName;
	}
};