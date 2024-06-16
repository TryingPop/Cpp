/*
��¥ : 2023. 2. 9
�̸� : �輺��
���� : ������� ���� ���α׷�
	Ch01 06�� 01�� ����� �߰�����

	Acccount Ŭ������ ����ϴ� ���� �� Ŭ������ �߰� ����
	
	������ ���� �� ó����Ŀ� ����
	NormalAccount ���뿹�ݰ���
	HighCreditAccount �ſ�ŷڰ���
	�� Ŭ������ �߰� ����

	���뿹�ݰ��¸� �ǹ��ϴ� NoramlAccount Ŭ������ ��ü�� ������������ ���� ������ ����� �� �ֵ��� ��������
	�ݸ� �ſ�ŷڰ��¸� �ǹ��ϴ� HighCreditAccount Ŭ�������� ������ Ư���� �ο��ؼ� ��������
		NormalAccount Ŭ������ ���������� ��ü ������������ �⺻������ ����� ���ִ�
		���� �ſ����� A, B, C�� ������ ���°��� �� �� ������ ����Ѵ�
		A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2%�� ������ �߰��� �����Ѵ�

	��� ���¿� ���� ���� ������ ������ ��������
		���°��� �������� �ʱ� �ԱݵǴ� �ݾ׿� ���ؼ��� ���ڸ� ������� �ʴ´�
		���°��� �� ������ �Աݰ����� ��ĥ ������ ���ڰ� �߻��ϴ� ������ �����Ѵ�
		������ ���������� �߻��ϴ� �Ҽ��� ������ �ݾ��� �����Ѵ�

	��Ʈ�� Ŭ������ AccountHandler Ŭ�������� ū ��ȭ�� ����� �Ѵ�

	������ ��

	[������ ��������1]
	-----Menu------
	1. ���°���
	2. �� ��
	3. �� ��
	4. �������� ��ü ���
	5. ���α׷� ����
	����: 1

	[������������]
	1. ���뿹�ݰ��� 2. �ſ�ŷڰ���
	����: 1
	[���뿹�ݰ��� ����]
	����ID: 123
	��  ��: LeeHong
	�Աݾ�: 0
	������: 3

	[������ ��������2]
	-----Menu------
	1. ���°���
	2. �� ��
	3. �� ��
	4. �������� ��ü ���
	5. ���α׷� ����
	����: 1

	[������������]
	1. ���뿹�ݰ��� 2. �ſ�ŷڰ���
	[�ſ�ŷڰ��� ����]
	����ID: 7272
	��  ��: POarkJun
	�Աݾ�: 10000
	������: 9
	�ſ���(1toA, 2toB, 3toC): 2
*/

// ������ �ۼ�
#define _CRT_SECURE_NO_WARNINGS		// vs���� strcpy�� ���
#include<iostream>					
#include<cstring>					
using namespace std;

class Account {	// �� 

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

			cout << "�ܾ��� �����մϴ�." << endl;
			return;
		}

		this->money -= money;
	}

	virtual void ShowInfo() const = 0 {

		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << name << endl;
		cout << "�Աݾ�: " << money << endl;
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
		cout << "������: " << interest << endl;
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
		cout << "�ſ���: " << GetRankChar() << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
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
			cout << "���α׷� ����" << endl;
			break;

		default:
			cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
			break;
		}

		cout << endl;
	}

	void CreateAccount() {

		int create;
		cout << "[������������]" << endl;
		cout << "1. ���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
		cout << "����: "; cin >> create;

		int accID;
		char name[30];
		int money;
		int interest;

		if (create == NORMAL) {

			cout << "[���뿹�ݰ��� ����]" << endl;
		}
		else {

			cout << "[�ſ�ŷڰ��� ����]" << endl;
		}

		cout << "����ID: "; cin>> accID;
		cout << "��  ��: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;
		cout << "������: "; cin >> interest;

		if (create == NORMAL) {

			if (ChkAccID(accID) != -1) {

				cout << "�̹� �����ϴ� �����Դϴ�." << endl;
				return;
			}

			customers[cusNum++] = new NormalAccount(accID, name, money, interest);
		}
		else {

			int rank;
			cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> rank;

			if (ChkAccID(accID) != -1) {

				cout << "�̹� �����ϴ� �����Դϴ�." << endl;
				return;
			}

			customers[cusNum++] = new HighCreditAccount(accID, name, money, interest, rank);
		}
	}

	void DepositMoney() {

		int accID;
		int money;
		int chk;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "�Աݾ�: "; cin >> money;

		chk = ChkAccID(accID);
		if (chk == -1) {

			cout << "��ϵ��� ���� ���¹�ȣ �Դϴ�." << endl;
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

		chk = ChkAccID(accID);
		if (chk == -1) {

			cout << "��ϵ��� ���� ���¹�ȣ �Դϴ�." << endl;
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