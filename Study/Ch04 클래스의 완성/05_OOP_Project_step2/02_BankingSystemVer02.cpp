/*
날짜 : 2023. 1. 30
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Account 클래스의 정의, 객체 포인터 배열 적용

	클래스 배열 선언하고 new를 쓰는거보니
	NULL로 채우는거 같다
	추후에 따로 C에서 배열 알아보기 필요
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account {

private:
	int accID;		// 계좌번호
	int balance;	// 잔    액
	char* cusName;	// 고객이름

public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money), cusName(name) {

		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int GetAccId() { return accID; }

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

Account* accArr[100];	// Account 저장을 위한 배열
int accNum = 0;

int main(void) 
{

	int choice;

	while (1) {

		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {

		case MAKE:
			MakeAccount();
			break;

		case DEPOSIT:
			DepositMoney();
			break;

		case WITHDRAW:
			WithdrawMoney();
			break;

		case INQUIRE:
			ShowAllAccInfo();
			break;

		case EXIT:
			for (int i = 0; i < accNum; i++) {

				delete accArr[i];
			}

			return 0;
		}
	}

	return 0;
}

void ShowMenu() {

	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) {

	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {

	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccId() == id) {

			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl;
}

void WithdrawMoney() {

	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i]->GetAccId() == id) {

			if (accArr[i]->Withdraw(money) == 0) {

				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void) {

	for (int i = 0; i < accNum; i++) {

		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}