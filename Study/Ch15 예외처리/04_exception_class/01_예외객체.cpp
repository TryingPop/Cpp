/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ���ܰ�ü
	���ܹ߻��� �˸��µ� ���Ǵ� ��ü�� ������ ���ܰ�ü�� �Ѵ�

	�׸��� ���ܰ�ü�� ������ ���� ���ǵ� Ŭ������ ���� Ŭ������ �Ѵ�.

	�Ʒ��� ATM���� ���������ϴ� �ù����̼��� �����̴�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class DepositException {

private:
	int reqDep;		// ��û �Աݾ�

public:
	DepositException(int money)
		: reqDep(money) { }

	void ShowExceptionReason() {

		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
	}
};

class WithdrawException {

private:
	int balance;	// �ܰ�

public:
	WithdrawException(int money)
		: balance(money) { }

	void ShowExceptionReason() {

		cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���]" << endl;
	}
};

class Account {

private:
	char accNum[50];	// ���¹�ȣ
	int balance;		// �ܰ�

public:
	Account(const char* acc, int money) 
		: balance(money) {

		strcpy(accNum, acc);
	}

	void Deposit(int money) throw (DepositException) {

		if (money < 0) {

			DepositException expn(money);
			throw expn;
		}

		balance += money;
	}

	void Withdraw(int money) throw (WithdrawException) {

		if (money > balance) {

			throw WithdrawException(balance);
		}

		balance -= money;
	}

	void ShowMyMoney() {

		cout << "�ܰ�: " << balance << endl << endl;
	}
};

int main(void)
{

	Account myAcc("56789-827120", 5000);

	try {

		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (DepositException& expn) {

		expn.ShowExceptionReason();	// [���� �޽���: -300�� �ԱݺҰ�]
	}

	myAcc.ShowMyMoney();	// 7000

	try {

		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException& expn) {

		expn.ShowExceptionReason();	// [���� �޽���: �ܾ� 3500, �ܾ׺���]
	}

	myAcc.ShowMyMoney();	// 3500
	return 0;
}