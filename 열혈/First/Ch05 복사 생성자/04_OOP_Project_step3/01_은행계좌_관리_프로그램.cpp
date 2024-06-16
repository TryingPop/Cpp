/*
��¥ : 2023. 2. 2
�̸� : �輺��
���� : ������� ���� ���α׷�
	Ch01 06�� 01�� ���� �����ڸ� �̿��� ǥ������
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

		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << name << endl;
		cout << "��  ��: " << money << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "�ܾ� �ʰ��Դϴ�." << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ������ Ȯ��" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: "; cin >> choice;
	cout << endl;
}

void CreateAccount() {

	int accID;
	char name[30];
	int money;

	cout << "����ID: "; cin >> accID;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;

	if (ChkAccID(accID) != -1) {

		cout << "�̹� �����ϴ� ���¹�ȣ �Դϴ�." << endl;
		return;
	}

	customers[cusNum++] = new Customer(accID, name, money);
}

void DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "����ID: "; cin >> accID;
	cout << "�Աݾ�: "; cin >> money;

	chk = ChkAccID(accID);

	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�" << endl;
		return;
	}

	customers[chk]->Deposit(money);
}

void WithdrawMoney() {

	int accID;
	int money;
	int chk;

	cout << "����ID: "; cin >> accID;
	cout << "��ݾ�: "; cin >> money;

	chk = ChkAccID(accID);

	if (chk == -1) {

		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�" << endl;
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
		cout << "���α׷� ����" << endl;
		break;

	default:
		cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
		break;
	}

	cout << endl;
}