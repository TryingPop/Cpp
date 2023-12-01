/*
��¥ : 2023. 2. 5
�̸� : �輺��
���� : ������� ���� ���α׷�
	Ch01 06�� 01�� ��Ʈ�� Ŭ������ �̿�����

	Entity Ŭ����
		�������� ������ ���ϴ�
			���� ������ ���̽��� ����Ǵ� �����͸� �����ϰ� �ִ�
		���α׷��� ����� �ľ��ϴµ� ������ ������ ���Ѵ�
		�׷��� ���α׷��󿡼� �����Ǵ� �������� ������ �ľ��ϴ� ���� ������ �ȴ�

	��Ʈ�� Ŭ����
		���α׷� ��ü�� ����� ����Ѵ�
			���� ����� ������ ���� Ŭ�����̴�
		��Ʈ�� Ŭ������ ���� ���α׷��� ��ü ��ɰ� �帧�� �ľ��� �� �ִ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Entity Ŭ����
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

		cout << "���¹�ȣ : " << accID << endl;
		cout << "�� �� : " << name << endl;
		cout << "�� �� : " << money << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "�ܾ��� �����մϴ�." << endl;
			return;
		}

		this->money -= money;
	}

	~Customer() {

		delete[] name;
	}
};

// ��Ʈ�� Ŭ����
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

		cout << "[���°���]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;

		if (FindAccID(accID) != -1) {

			cout << "�̹� �����ϴ� ���¹�ȣ �Դϴ�." << endl;
			return;
		}

		customers[cusNum++] = new Customer(accID, name, money);
	}

	void DepositMoney() {

		int accID;
		int money;
		int chk;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "�Աݾ�: "; cin >> money;

		chk = FindAccID(accID);
		if (chk == -1) {

			cout << "�������� �ʴ� �����Դϴ�" << endl;
			return;
		}

		customers[chk]->Deposit(money);
	}

	void WithdrawMoney() {

		int accID;
		int money;
		int chk;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "��ݾ�: "; cin >> money;

		chk = FindAccID(accID);
		if (chk == -1) {

			cout << "�������� �ʴ� �����Դϴ�" << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. ������ ��ȸ" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: "; cin >> choice;
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
			cout << "���α׷� ����";
			break;

		default:
			cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
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