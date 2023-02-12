/*
날짜 : 2023. 2. 12
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 397p

	코드파일 : Main 함수
*/

#include "13_AccountHandler.h"
#include "15_BankingCommonDecl.h"

int main(void) 
{

	AccountHandler manager;
	int choice;

	while (1) {
		
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {

		case MAKE:
			manager.MakeAccount();
			break;

		case DEPOSIT:
			manager.DepositMoney();
			break;

		case WITHDRAW:
			manager.WithdrawMoney();
			break;

		case INQUIRE:
			manager.ShowAllAccInfo();
			break;

		case EXIT:
			return 0;

		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}