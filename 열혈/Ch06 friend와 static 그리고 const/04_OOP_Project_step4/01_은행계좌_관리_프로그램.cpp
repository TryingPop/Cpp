/*
날짜 : 2023. 2. 3
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Ch01 06의 01을 const 키워드를 이용해 완성도를 높이자
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Customer {

private:
	const int accID;
	char* name;
	int money;

public:
	Customer(int accID, char* name, int money) 
		: accID(accID), money(money) {

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Customer(Customer& copy) 
		: accID(copy.accID), money(copy.money) {

		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetAccID() const {

		return accID;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "잔액이 부족합니다." << endl;
		}

		this->money -= money;
	}

	void ShowInfo() const {

		cout << "계좌번호: " << accID << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << money << endl;
	}

	~Customer() {

		delete[] name;
	}
};

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
Customer* customers[100];
int cusNum = 0;
int choice = 0;

void ShowMenu();		// 메뉴 보여주기
void CreateAccount();	// 계좌개설
void DepositMoney();	// 입금
void WithdrawMoney();	// 출금
void ShowAllAccInfo();	// 고객정보 조회

int FindAccID(int accID);		// accID로 고객정보 찾기
void SelectOpt();		// 선택한 옵션으로 기능 실행

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
	cout << "2. 입  금" << endl;
	cout << "3. 출  금" << endl;
	cout << "4. 계좌정보 조회" << endl;
	cout << "5. 종료" << endl;
	cout << "선택: "; cin >> choice;
	cout << endl;
}

void CreateAccount() {

	int accID;
	char name[30];
	int money;
	int chk;	// 계좌번호 중복체크

	// 배열 다차서 계좌 생성 불가능
	if (cusNum >= 100) {

		cout << "더이상 계좌를 생성할 수 없습니다." << endl;
		return;
	}

	cout << "[계좌개설]" << endl;
	cout << "계좌번호: "; cin >> accID;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;

	// 이미 존재하는 계좌번호인지 존재하는지 확인
	chk = FindAccID(accID);
	if (chk != -1) {

		cout << "이미 존재하는 계좌입니다." << endl;
		return;
	}

	// 계좌개설
	customers[cusNum++] = new Customer(accID, name, money);
}

void DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "[입  금]" << endl;
	cout << "계좌번호: "; cin >> accID;
	cout << "입금액: "; cin >> money;

	// 계좌번호가 존재하는지 확인
	chk = FindAccID(accID);
	if (chk == -1) {

		cout << "존재하지 않는 계좌입니다." << endl;
		return;
	}

	// 입금
	customers[chk]->Deposit(money);
}


void WithdrawMoney() {

	int accID;
	int money;
	int chk;
	
	cout << "[출  금]" << endl;
	cout << "계좌번호: "; cin >> accID;
	cout << "출금액: "; cin >> money;

	//계좌번호가 존재하는지 확인
	chk = FindAccID(accID);
	if (chk == -1) {

		cout << "존재하지 않는 계좌입니다." << endl;
		return;
	}

	// 출금
	customers[chk]->Withdraw(money);
}

void ShowAllAccInfo() {

	for (int i = 0; i < cusNum; i++) {

		customers[i]->ShowInfo();
	}
}

int FindAccID(int accID) {

	for (int i = 0; i < cusNum; i++) {

		if (customers[i]->GetAccID() == accID) {

			// 존재하면 배열 번호 반환
			return i;
		}
	}

	// 존재하지 않는 경우
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
		ShowAllAccInfo();
		break;

	case EXIT:
		cout << "프로그램 종료" << endl;
		break;

	default:
		cout << "잘못된 번호를 입력하셨습니다." << endl;
		break;
	}

	cout << endl << endl;
}