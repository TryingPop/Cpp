/*
��¥ : 2023. 2. 3
�̸� : �輺��
���� : ������� ���� ���α׷�
	Ch01 06�� 01�� const Ű���带 �̿��� �ϼ����� ������
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

			cout << "�ܾ��� �����մϴ�." << endl;
		}

		this->money -= money;
	}

	void ShowInfo() const {

		cout << "���¹�ȣ: " << accID << endl;
		cout << "�̸�: " << name << endl;
		cout << "�ܾ�: " << money << endl;
	}

	~Customer() {

		delete[] name;
	}
};

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
Customer* customers[100];
int cusNum = 0;
int choice = 0;

void ShowMenu();		// �޴� �����ֱ�
void CreateAccount();	// ���°���
void DepositMoney();	// �Ա�
void WithdrawMoney();	// ���
void ShowAllAccInfo();	// ������ ��ȸ

int FindAccID(int accID);		// accID�� ������ ã��
void SelectOpt();		// ������ �ɼ����� ��� ����

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
	cout << "2. ��  ��" << endl;
	cout << "3. ��  ��" << endl;
	cout << "4. �������� ��ȸ" << endl;
	cout << "5. ����" << endl;
	cout << "����: "; cin >> choice;
	cout << endl;
}

void CreateAccount() {

	int accID;
	char name[30];
	int money;
	int chk;	// ���¹�ȣ �ߺ�üũ

	// �迭 ������ ���� ���� �Ұ���
	if (cusNum >= 100) {

		cout << "���̻� ���¸� ������ �� �����ϴ�." << endl;
		return;
	}

	cout << "[���°���]" << endl;
	cout << "���¹�ȣ: "; cin >> accID;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;

	// �̹� �����ϴ� ���¹�ȣ���� �����ϴ��� Ȯ��
	chk = FindAccID(accID);
	if (chk != -1) {

		cout << "�̹� �����ϴ� �����Դϴ�." << endl;
		return;
	}

	// ���°���
	customers[cusNum++] = new Customer(accID, name, money);
}

void DepositMoney() {

	int accID;
	int money;
	int chk;

	cout << "[��  ��]" << endl;
	cout << "���¹�ȣ: "; cin >> accID;
	cout << "�Աݾ�: "; cin >> money;

	// ���¹�ȣ�� �����ϴ��� Ȯ��
	chk = FindAccID(accID);
	if (chk == -1) {

		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	// �Ա�
	customers[chk]->Deposit(money);
}


void WithdrawMoney() {

	int accID;
	int money;
	int chk;
	
	cout << "[��  ��]" << endl;
	cout << "���¹�ȣ: "; cin >> accID;
	cout << "��ݾ�: "; cin >> money;

	//���¹�ȣ�� �����ϴ��� Ȯ��
	chk = FindAccID(accID);
	if (chk == -1) {

		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	// ���
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

			// �����ϸ� �迭 ��ȣ ��ȯ
			return i;
		}
	}

	// �������� �ʴ� ���
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
		cout << "���α׷� ����" << endl;
		break;

	default:
		cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�." << endl;
		break;
	}

	cout << endl << endl;
}