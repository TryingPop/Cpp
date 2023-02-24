/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외객체
	예외발생을 알리는데 사용되는 객체를 가리켜 예외객체라 한다

	그리고 예외객체의 생성을 위해 정의된 클래스를 예외 클래스라 한다.

	아래는 ATM에서 돈인출을하는 시물레이션을 예제이다
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class DepositException {

private:
	int reqDep;		// 요청 입금액

public:
	DepositException(int money)
		: reqDep(money) { }

	void ShowExceptionReason() {

		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException {

private:
	int balance;	// 잔고

public:
	WithdrawException(int money)
		: balance(money) { }

	void ShowExceptionReason() {

		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

class Account {

private:
	char accNum[50];	// 계좌번호
	int balance;		// 잔고

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

		cout << "잔고: " << balance << endl << endl;
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

		expn.ShowExceptionReason();	// [예외 메시지: -300는 입금불가]
	}

	myAcc.ShowMyMoney();	// 7000

	try {

		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException& expn) {

		expn.ShowExceptionReason();	// [예외 메시지: 잔액 3500, 잔액부족]
	}

	myAcc.ShowMyMoney();	// 3500
	return 0;
}