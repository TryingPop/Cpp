/*
날짜 : 2023. 2. 9
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	Ch01 06의 01에 상속을 추가하자

	Acccount 클래스를 상속하는 다음 두 클래스를 추가 정의
	
	이자의 지급 및 처리방식에 따라
	NormalAccount 보통예금계좌
	HighCreditAccount 신용신뢰계좌
	두 클래스를 추가 정의

	보통예금계좌를 의미하는 NoramlAccount 클래스는 객체의 생성과정에서 이율 정보를 등록할 수 있도록 정의하자
	반면 신용신뢰계좌를 의미하는 HighCreditAccount 클래스에는 다음의 특성을 부여해서 정의하자
		NormalAccount 클래스와 마찬가지로 객체 생성과정에서 기본이율을 등록할 수있다
		고객의 신용등급을 A, B, C로 나누고 계좌개설 시 이 정보를 등록한다
		A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다

	모든 계좌에 대해 공히 다음의 조건을 적용하자
		계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자를 계산하지 않는다
		계좌개설 후 별도의 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주한다
		이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다

	컨트롤 클래스인 AccountHandler 클래스에는 큰 변화가 없어야 한다

	실행의 예

	[계좌의 개설과정1]
	-----Menu------
	1. 계좌개설
	2. 입 금
	3. 출 금
	4. 계좌정보 전체 출력
	5. 프로그램 종료
	선택: 1

	[계좌종류선택]
	1. 보통예금계좌 2. 신용신뢰계좌
	선택: 1
	[보통예금계좌 개설]
	계좌ID: 123
	이  름: LeeHong
	입금액: 0
	이자율: 3

	[계좌의 개설과정2]
	-----Menu------
	1. 계좌개설
	2. 입 금
	3. 출 금
	4. 계좌정보 전체 출력
	5. 프로그램 종료
	선택: 1

	[계좌종류선택]
	1. 보통예금계좌 2. 신용신뢰계좌
	[신용신뢰계좌 개설]
	계좌ID: 7272
	이  름: POarkJun
	입금액: 10000
	이자율: 9
	신용등급(1toA, 2toB, 3toC): 2
*/

// 스스로 작성
#define _CRT_SECURE_NO_WARNINGS		// vs에서 strcpy의 사용
#include<iostream>					
#include<cstring>					
using namespace std;

class Account {	// 고객 

private:
	int accID;
	char* name;
	int money;

public:
	Account(int accID, const char* name, int money) 
		: accID(accID), money(money) {

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int GetAccID() const {

		return accID;
	}

	virtual void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "잔액이 부족합니다." << endl;
			return;
		}

		this->money -= money;
	}

	virtual void ShowInfo() const = 0 {

		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << name << endl;
		cout << "입금액: " << money << endl;
	}

	~Account() {

		delete[] name;
	}
};

class NormalAccount : public Account {

protected:
	int interest;

public:
	NormalAccount(int accID, const char* name, int money, int interest)
		: Account(accID, name, money), interest(interest) { }

	int GetInterest() {

		return interest;
	}

	virtual void Deposit(int money) {

		money += (int)(((float)(interest * money)) / 100);
		Account::Deposit(money);
	}

	virtual void ShowInfo() const {

		Account::ShowInfo();
		cout << "이자율: " << interest << endl;
	}
};

class HighCreditAccount : public NormalAccount {

private:
	int rank;
	enum{ RANK_A =1, RANK_B, RANK_C };
public:
	HighCreditAccount(int accID, const char* name, int money, int interest, int rank) 
		: NormalAccount(accID, name, money, interest), rank(rank) { }

	int GetRankInterest() const {

		if (rank == RANK_A) {

			return 7;
		}
		else if (rank == RANK_B) {

			return 4;
		}
		else {

			return 3;
		}

	}

	char GetRankChar() const {

		if (rank == RANK_A) {

			return 'A';
		}
		else if (rank == RANK_B) {

			return 'B';
		}
		else {

			return 'C';
		}
	}

	virtual void Deposit(int money) {

		money += (int)(((float)(interest + GetRankInterest()) * money) / 100);
		Account::Deposit(money);
	}

	virtual void ShowInfo() const {

		NormalAccount::ShowInfo();
		cout << "신용등급: " << GetRankChar() << endl;
	}
};

class AccountHandler {

private:
	Account* customers[100];
	int cusNum;
	int choice;
	
	enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
	enum { NORMAL = 1, CREDIT };

public:
	AccountHandler()
		: cusNum(0), choice(0) { }

	void Start() {

		while (choice != EXIT) {

			ShowMenu();
			SelectOpt();
		}
	}

	void ShowMenu() {

		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
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
			cout << "프로그램 종료" << endl;
			break;

		default:
			cout << "잘못된 입력을 하였습니다." << endl;
			break;
		}

		cout << endl;
	}

	void CreateAccount() {

		int create;
		cout << "[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌 2.신용신뢰계좌" << endl;
		cout << "선택: "; cin >> create;

		int accID;
		char name[30];
		int money;
		int interest;

		if (create == NORMAL) {

			cout << "[보통예금계좌 개설]" << endl;
		}
		else {

			cout << "[신용신뢰계좌 개설]" << endl;
		}

		cout << "계좌ID: "; cin>> accID;
		cout << "이  름: "; cin >> name;
		cout << "입금액: "; cin >> money;
		cout << "이자율: "; cin >> interest;

		if (create == NORMAL) {

			if (ChkAccID(accID) != -1) {

				cout << "이미 존재하는 계좌입니다." << endl;
				return;
			}

			customers[cusNum++] = new NormalAccount(accID, name, money, interest);
		}
		else {

			int rank;
			cout << "신용등급(1toA, 2toB, 3toC): "; cin >> rank;

			if (ChkAccID(accID) != -1) {

				cout << "이미 존재하는 계좌입니다." << endl;
				return;
			}

			customers[cusNum++] = new HighCreditAccount(accID, name, money, interest, rank);
		}
	}

	void DepositMoney() {

		int accID;
		int money;
		int chk;

		cout << "[입    금]" << endl;
		cout << "계좌ID: "; cin >> accID;
		cout << "입금액: "; cin >> money;

		chk = ChkAccID(accID);
		if (chk == -1) {

			cout << "등록되지 않은 계좌번호 입니다." << endl;
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

		chk = ChkAccID(accID);
		if (chk == -1) {

			cout << "등록되지 않은 계좌번호 입니다." << endl;
			return;
		}

		customers[chk]->Withdraw(money);
	}

	void ShowAllAccInfo() const {

		for (int i = 0; i < cusNum; i++) {

			customers[i]->ShowInfo();
		}
	}

	int ChkAccID(int accID) {

		for (int i = 0;i < cusNum;i++) {

			if (accID == customers[i]->GetAccID()) {

				return i;
			}
		}

		return -1;
	}

	~AccountHandler() {

		for (int i = 0; i < cusNum; i++) {

			delete customers[i];
		}
	}
};


int main(void) 
{

	AccountHandler program;

	program.Start();
	return 0;
}