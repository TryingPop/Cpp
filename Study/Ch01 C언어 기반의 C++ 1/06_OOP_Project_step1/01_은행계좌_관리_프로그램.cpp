#include <iostream>
#include <cstring>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

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

// 스스로 구현

// 함수 선언
void ShowMenu();					// 메뉴 보여주기
void SelectFunction(int *choice);	// 기능 선택
void StartFunction(int choice);		// 기능 시작
void CreateAccount();				// 계좌 생성
int CheckAccount(int id);			// 계좌 확인
void DepositMoney();				// 예금
void WithdrawMoney();				// 출금
void ShowAllAccount();				// 전체 계좌 출력

enum {Create = 1, Deposit, Withdraw, Inquire, Exit};

// 계정 구조체
typedef struct {

	int accId;
	char name[30];
	int money;
} Account;

// 계정 배열
Account accArr[100];
int accNum = 0;

int main() 
{

	int choice = 0;

	while (choice != Exit) {

		ShowMenu();
		SelectFunction(&choice);
		StartFunction(choice);
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

void SelectFunction(int* choice) {

	cout << "선택 : ";
	cin >> *choice;
	cout << endl;
}

void StartFunction(int choice) {

	switch (choice) {

		case Create:
			CreateAccount();
			break;

		case Deposit:
			DepositMoney();
			break;

		case Withdraw:
			WithdrawMoney();
			break;

		case Inquire:
			ShowAllAccount();
			break;

		case Exit:
			cout << "프로그램을 종료합니다.";
			break;

		default:
			cout << "잘못된 값을 입력했습니다." << endl;
			break;
	}
}

void CreateAccount() {

	// 변수 선언
	int id;
	char name[30];
	int money;

	// 값 입력
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	cout << endl;

	// 입력한 값 계좌에 대입
	accArr[accNum].accId = id;
	accArr[accNum].money = money;
	strcpy_s(accArr[accNum].name, name);
	accNum++;
}

int CheckAccount(int id) {

	for (int i = 0; i < accNum; i++) {

		if (accArr[i].accId == id) {

			return i;
		}
	}
	
	return -1;
}

void DepositMoney() {

	int id;
	int money;
	int arrNum;
	cout << "[입   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> money;

	arrNum = CheckAccount(id);
	if (arrNum == -1) {

		cout << "등록되지 않은 계좌입니다." << endl;
	}
	else {

		accArr[arrNum].money += money;
		cout << "입금완료" << endl;
	}
}

void WithdrawMoney() {

	int id;
	int money;
	int arrNum;

	cout << "[출   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> money;

	arrNum = CheckAccount(id);
	if (arrNum == -1) {

		cout << "등록되지 않은 계좌입니다." << endl;
	}
	else if (accArr[arrNum].money < money) {

		cout << "잔액이 부족합니다." << endl;
	}
	else {

		accArr[arrNum].money -= money;
		cout << "출금완료" << endl;
	}
}

void ShowAllAccount() {

	for (int i = 0; i < accNum; i++) {

		cout << "계좌ID : " << accArr[i].accId << endl;
		cout << "이 름 : " << accArr[i].name << endl;
		cout << "잔 액 : " << accArr[i].money << endl;
		cout << endl;
	}
}