/*
��¥ : 2023. 2. 20
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 397p

	�ڵ����� : Main �Լ� 
*/

#include "19_BankingCommonDecl.h"
#include "13_AccountHandler.h"

int main(void) 
{

	AccountHandler manager;
	int choice;

	while (1) {

		manager.ShowMenu();
		cout << "����: ";
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
			cout << "Illega selection.." << endl;
			break;
		}
	}

	return 0;
}