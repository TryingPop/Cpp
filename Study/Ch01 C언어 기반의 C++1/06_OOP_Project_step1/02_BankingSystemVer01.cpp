/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 은행계좌 프로그램
	여기서는 C 스타일로 구현하는 것을 목표로 한다.
	기능 1. 계좌개설
	기능 2. 입    금
	기능 3. 출    금
	기능 4. 전체고객 잔액조회
	계좌 개설 과정의 실행 예
	-----Menu------
	1. 계좌개설
	2. 입 금
	3. 출 금
	4. 계좌정보 전체 출력
	5. 프로그램 종료
	선택 : 1
	[계좌개설]
	계좌ID : 115
	이름 : 이우석
	입금액 : 15000
	입금 및 정보 조회의 예
	-----Menu------
	1. 계좌개설
	2. 입 금
	3. 출 금
	4. 계좌정보 전체 출력
	5. 프로그램 종료
	선택 : 2
	[입   금]
	계좌ID : 115
	입금액 : 70
	입금완료
	-----Menu------
	1. 계좌개설
	2. 입 금
	3. 출 금
	4. 계좌정보 전체 출력
	5. 프로그램 종료
	선택 : 4
	계좌ID : 115
	이 름 : 이우석
	잔 액 : 15070
*/

// 교재 53p 예제

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);		// 메뉴출력
void MakeAccount(void);		// 계좌개설을 위한 함수
void DepositMoney(void);	// 입    금
void WithdrawMoney(void);	// 출    금
void ShowAllAccInfo(void);	// 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct {

	int accID;				// 계좌번호
	int balance;			// 잔액
	char cusName[NAME_LEN];	// 고객이름
} Account;

Account accArr[100];		// Account 저장을 위한 배열
int accNum = 0;				// 저장된 Account 수

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
			return 0;

		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

void ShowMenu(void) {

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
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMont(void) {

	int money;
	int id;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i].accID == id) {

			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void) {

	int money;
	int id;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {

		if (accArr[i].accID) {

			if (accArr[i].balance < money) {

				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void) {

	for (int i = 0; i < accNum; i++) {

		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이 름: " << accArr[i].cusName << endl;
		cout << "잔 액: " << accArr[i].balance << endl << endl;
	}
}