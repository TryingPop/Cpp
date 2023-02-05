/*
날짜 : 2023. 2. 5
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Ch01 06의 01을 컨트롤 클래스를 이용하자

	Entity 클래스
		데이터적 성격이 강하다
			따라서 데이터 베이스에 저장되는 데이터를 소유하고 있다
		프로그램의 기능을 파악하는데 도움을 주지는 못한다
		그러나 프로그램상에서 관리되는 데이터의 종류를 파악하는 데는 도움이 된다

	컨트롤 클래스
		프로그램 전체의 기능을 담당한다
			따라서 기능적 성격이 강한 클래스이다
		컨트롤 클래스만 봐도 프로그램의 전체 기능과 흐름을 파악할 수 있다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Entity 클래스
class Customer {

private:
	int accID;
	char* name;
	int money;

public:
	Customer(int accID, char* name, int money)
		: accID(accID), money(money) {

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int GetAccID() const { return accID; }

	void ShowInfo() const {

		cout << "계좌번호 : " << accID << endl;
		cout << "이 름 : " << name << endl;
		cout << "잔 액 : " << money << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "잔액이 부족합니다." << endl;
			return;
		}

		this->money -= money;
	}

	~Customer() {

		delete[] name;
	}
};

// 컨트롤 클래스
class Bank {

private:
	Customer* customers[100];
	int cusNum;
	int choice;
	enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

public:
	Bank()
		: cusNum(0), choice(0) { }

	void CreateAccount() {

		int accID;
		char name[30];
		int money;

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: "; cin >> accID;
		cout << "이름: "; cin >> name;
		cout << "입금액: "; cin >> money;

		if (FindAccID(accID) != -1) {

			cout << "이미 존재하는 계좌번호 입니다." << endl;
			return;
		}

		customers[cusNum++] = new Customer(accID, name, money);
	}

	void DepositMoney() {

		int accID;
		int money;
		int chk;

		cout << "[입    금]" << endl;
		cout << "계좌ID: "; cin >> accID;
		cout << "입금액: "; cin >> money;

		chk = FindAccID(accID);
		if (chk == -1) {

			cout << "존재하지 않는 계좌입니다" << endl;
			return;
		}

		customers[chk]->Deposit(money);
	}

	void WithdrawMoney() {

		int accID;
		int money;
		int chk;

		cout << "[출    금]" << endl;
		cout << "계좌ID: "; cin >> accID;
		cout << "출금액: "; cin >> money;

		chk = FindAccID(accID);
		if (chk == -1) {

			cout << "존재하지 않는 계좌입니다" << endl;
			return;
		}

		customers[chk]->Withdraw(money);
	}

	void ShowAllAccInfo() const {

		for (int i = 0; i < cusNum; i++) {

			customers[i]->ShowInfo();
		}
	}

	int FindAccID(int accID) const {

		for (int i = 0; i < cusNum; i++) {

			if (customers[i]->GetAccID() == accID) {

				return i;
			}
		}

		return -1;
	}

	void Start() {
	
		while (choice != 5) {

			ShowMenu();
			SelectOpt();
		}
	}


	void ShowMenu() {

		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 고객정보 조회" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: "; cin >> choice;
		cout << endl;
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
			cout << "프로그램 종료";
			break;

		default:
			cout << "잘못된 입력을 하였습니다." << endl;
			break;
		}

		cout << endl;
	}

	~Bank() {

		for (int i = 0; i < cusNum; i++) {

			delete customers[i];
		}
	}
};

int main(void) 
{

	Bank bk;
	bk.Start();
}