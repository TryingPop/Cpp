/*
��¥ : 2023. 1. 29
�̸� : �輺��
���� : ������� ���� ���α׷�
	Ch01 06�� 01�� Ŭ������ �̿��� ǥ������
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

		// ���⿡ ���� �ִ�
		this->accId = accId; // ���⼭ �ٷ� ����
		this->name = (char*)malloc(strlen(name) + 1);
		
		
		strcpy(this->name, name);
		this->money = money;
	}

	void ShowInfo() {

		cout << "����ID: ";
		cout << accId << endl;
		cout << "�̸�: ";
		cout << name << endl;
		cout << "�ܾ�: ";
		cout << money << endl << endl;
	}

	void Deposit(int money) {

		this->money += money;
	}

	void Withdraw(int money) {

		if (this->money < money) {

			cout << "���忡 �ܾ��� �����մϴ�" << endl;
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

			cout << "���� �� �ڸ��� �����ϴ�." << endl;
			return;
		}

		if (ChkId(accId) != -1) {

			cout << "�̹� �����ϴ� �����Դϴ�." << endl;
			return;
		}

		customers[cusNums]->SetInfo(accId, name, money);	// ���⼭ 1������ ���� �߻�!
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
			cout << "�������� �ʴ� �����Դϴ�." << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
		cin >> optNum;

		cout << endl << endl;
	}

	void CreateAccount() {

		int accId;
		char name[20];
		int money;

		cout << "����ID: ";
		cin >> accId;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> money;

		bk.CreateAccount(accId, name, money);
	}

	void DepositMoney() {

		int accId;
		int money;
		Customer* cs;

		cout << "[��   ��]" << endl;
		cout << "����ID: ";
		cin >> accId;
		cout << "�Աݾ�: ";
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

		cout << "[��   ��]" << endl;
		cout << "����ID: ";
		cin >> accId;
		cout << "��ݾ�: ";
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
		
		cout << "���α׷� ����" << endl;;
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
			cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�." << endl;
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
	bk.customers[0]->SetInfo(1, "�ٺ�", 3);
	bk.customers[0]->ShowInfo();
}