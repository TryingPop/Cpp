/*
��¥ : 2023. 2. 2
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 240p
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define NAME_LEN	20
using namespace std;

class Account {

private:
	int accID;		// ���¹�ȣ
	int balance;	// ��    ��
	char* cusName;	// �����̸�

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

		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << cusName << endl;
		cout << "��  ��: " << balance << endl;
	}

	~Account() {

		delete[] cusName;
	}
};