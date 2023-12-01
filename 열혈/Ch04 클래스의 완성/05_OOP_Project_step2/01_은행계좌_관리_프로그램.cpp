/*
날짜 : 2023. 1. 29
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Ch01 06의 01을 클래스를 이용해 표현하자
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Customer {

private:
	char* name;
	int money;

public:
	int accId;

public:
	void SetInfo(int accId, const char* name, int money) 
	{

		// 여기에 문제 있다
		this->accId = accId; // 여기서 바로 종료
		this->name = (char*)malloc(strlen(name) + 1);
		
		
		strcpy(this->name, name);
		this->money = money;
	}

	void ShowInfo() {

		cout << "계좌ID: ";
		cout << accId << endl;
		cout << "이름: ";
		cout << name << endl;
		cout << "잔액: ";
		cout << money << endl << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "통장에 잔액이 부족합니다" << endl;
			return;
		}

		this->money -= money;
	}

	~Customer() {

		free(name);
	}
};

class Bank {

public:
	Customer* customers[100];
	int cusNums;

public:
	void CreateAccount(int accId, const char* name, int money) {

		if (cusNums >= 100) {

			cout << "고객이 들어갈 자리가 없습니다." << endl;
			return;
		}

		if (ChkId(accId) != -1) {

			cout << "이미 존재하는 꼐좌입니다." << endl;
			return;
		}

		customers[cusNums]->SetInfo(accId, name, money);	// 여기서 1차적인 오류 발생!
		cusNums++;
	}

	int ChkId(int accId) {

		for (int i = 0; i < cusNums; i++) {

			if (customers[i]->accId == accId) {

				return i;
			}
		}
		
		return -1;
	}

	Customer* GetCustomer(int accId) {

		int num = ChkId(accId);

		if (num == -1)
		{
			cout << "존재하지 않는 계좌입니다." << endl;
			return NULL;
		}

		return customers[num];
	}

	void ShowAllCustomers() {

		for (int i = 0; i < cusNums; i++) {

			customers[i]->ShowInfo();
		}
	}

	~Bank() {

		for (int i = 0; i < 100; i++) {

			free(customers[i]);
		}

		free(customers);
	}
};


class Program {

private:
	Bank bk;
	int optNum;
	enum {
		CREATE = 1,
		DEPOSIT = 2,
		WITHDRAW = 3,
		SHOWALLINFO = 4,
		QUIT = 5,
	};
private:
	void ShowMenu() {

		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> optNum;

		cout << endl << endl;
	}

	void CreateAccount() {

		int accId;
		char name[20];
		int money;

		cout << "계좌ID: ";
		cin >> accId;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;

		bk.CreateAccount(accId, name, money);
	}

	void DepositMoney() {

		int accId;
		int money;
		Customer* cs;

		cout << "[입   금]" << endl;
		cout << "계좌ID: ";
		cin >> accId;
		cout << "입금액: ";
		cin >> money;

		
		cs = bk.GetCustomer(accId);
		if ( cs != NULL) {

			cs->Deposit(money);
		}
	}

	void WithdrawMoney() {

		int accId;
		int money;
		Customer* cs;

		cout << "[출   금]" << endl;
		cout << "계좌ID: ";
		cin >> accId;
		cout << "출금액: ";
		cin >> money;

		cs = bk.GetCustomer(accId);
		if (cs != NULL) {

			cs->Withdraw(money);
		}
	}
	
	void ShowAllInfo() {

		bk.ShowAllCustomers();
	}

	void Quit() {
		
		cout << "프로그램 종료" << endl;;
	}

	void SelectOpt() {

		switch (optNum) {

		case CREATE:
			CreateAccount();
			break;
			
		case DEPOSIT:
			DepositMoney();
			break;

		case WITHDRAW:
			WithdrawMoney();
			break;

		case SHOWALLINFO:
			ShowAllInfo();
			break;

		case QUIT:
			Quit();
			break;

		default:
			cout << "잘못된 번호를 입력하셨습니다." << endl;
			break;
		}

		cout << endl << endl;
	}

public:
	void Start() {

		while (optNum != 5) {

			ShowMenu();
			SelectOpt();
		}

		free(this);
	}

	~Program() {

		free(&bk);
	}
};

int main(void) {

	// Program pg = * new Program();
	// pg.Start();
	Bank bk = * new Bank();
	bk.customers[0]->SetInfo(1, "바보", 3);
	bk.customers[0]->ShowInfo();
}