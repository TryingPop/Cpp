/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Ch01 06의 01을 복사 생성자를 이용해 표현하자
*/

#define _CRT_SECURE_NO_WARNINGS		//strcpy
#include <iostream>
#include <cstring>					
using namespace std;

class Customer {

private:
	int accID;
	char* name;
	int money;

public:
	Customer(int accID, const char* name, int money) 
		: accID(accID), money(money) {

		this->name = (char*)malloc(sizeof(int) * (strlen(name) + 1));
		strcpy(this->name, name);
	}

	Customer(Customer& copy)
		: accID(accID), money(money) {

		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetID() {

		return accID;
	}

	void ShowInfo() {

		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << name << endl;
		cout << "잔  액: " << money << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "잔액 초과입니다." << endl;
			return;
		}

		this->money -= money;
	}
	
	~Customer() {

		delete[] name;
	}
};

Customer* customers[100];
int choice = 0;
int cusNum = 0;
enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };


void ShowMenu();
void CreateAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllInfo();

int ChkAccID(int accID);
void SelectOpt();

int main(void) 
{

	while (choice != 5) {

		ShowMenu();
		SelectOpt();
	}
}

void ShowMenu() {

	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 고객정보 확인" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: "; cin >> choice;
	cout << endl;
}

void CreateAccount() {

	int accID;
	char name[30];
	int money;

	cout << "계좌ID: "; cin >> accID;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;

	if (ChkAccID(accID) != -1) {

		cout << "이미 존재하는 계좌번호 입니다." << endl;
		return;
	}

	customers[cusNum++] = new Customer(accID, name, money);
}

void DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "계좌ID: "; cin >> accID;
	cout << "입금액: "; cin >> money;

	chk = ChkAccID(accID);

	if (chk == -1) {

		cout << "존재하지 않는 계좌번호 입니다" << endl;
		return;
	}

	customers[chk]->Deposit(money);
}

void WithdrawMoney() {

	int accID;
	int money;
	int chk;

	cout << "계좌ID: "; cin >> accID;
	cout << "출금액: "; cin >> money;

	chk = ChkAccID(accID);

	if (chk == -1) {

		cout << "존재하지 않는 계좌번호 입니다" << endl;
		return;
	}

	customers[chk]->Withdraw(money);
}

void ShowAllInfo() {

	for (int i = 0; i < cusNum; i++) {

		customers[i]->ShowInfo();
		cout << endl;
	}
}


int ChkAccID(int accID) {

	for (int i = 0; i < cusNum; i++) {

		if (customers[i]->GetID() == accID) {

			return i;
		}
	}

	return -1;
}

void SelectOpt() {

	switch (choice) {

	case CREATE:
		CreateAccount();
		break;

	case DEPOSIT:
		DepositMoney();
		break;

	case WITHDRAW:
		WithdrawMoney();
		break;

	case INQUIRE:
		ShowAllInfo();
		break;
	
	case EXIT:
		cout << "프로그램 종료" << endl;
		break;

	default:
		cout << "잘못된 숫자를 입력하였습니다." << endl;
		break;
	}

	cout << endl;
}