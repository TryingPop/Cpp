#include <iostream>
#include <cstring>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : ������� ���α׷�
	���⼭�� C ��Ÿ�Ϸ� �����ϴ� ���� ��ǥ�� �Ѵ�.

	��� 1. ���°���
	��� 2. ��    ��
	��� 3. ��    ��
	��� 4. ��ü�� �ܾ���ȸ

	���� ���� ������ ���� ��
	-----Menu------
	1. ���°���
	2. �� ��
	3. �� ��
	4. �������� ��ü ���
	5. ���α׷� ����
	���� : 1

	[���°���]
	����ID : 115
	�̸� : �̿켮
	�Աݾ� : 15000

	�Ա� �� ���� ��ȸ�� ��
	-----Menu------
	1. ���°���
	2. �� ��
	3. �� ��
	4. �������� ��ü ���
	5. ���α׷� ����
	���� : 2

	[��   ��]
	����ID : 115
	�Աݾ� : 70
	�ԱݿϷ�

	-----Menu------
	1. ���°���
	2. �� ��
	3. �� ��
	4. �������� ��ü ���
	5. ���α׷� ����
	���� : 4

	����ID : 115
	�� �� : �̿켮
	�� �� : 15070
*/

// ������ ����

// �Լ� ����
void ShowMenu();					// �޴� �����ֱ�
void SelectFunction(int *choice);	// ��� ����
void StartFunction(int choice);		// ��� ����
void CreateAccount();				// ���� ����
int CheckAccount(int id);			// ���� Ȯ��
void DepositMoney();				// ����
void WithdrawMoney();				// ���
void ShowAllAccount();				// ��ü ���� ���

enum {Create = 1, Deposit, Withdraw, Inquire, Exit};

// ���� ����ü
typedef struct {

	int accId;
	char name[30];
	int money;
} Account;

// ���� �迭
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void SelectFunction(int* choice) {

	cout << "���� : ";
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
			cout << "���α׷��� �����մϴ�.";
			break;

		default:
			cout << "�߸��� ���� �Է��߽��ϴ�." << endl;
			break;
	}
}

void CreateAccount() {

	// ���� ����
	int id;
	char name[30];
	int money;

	// �� �Է�
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;
	cout << endl;

	// �Է��� �� ���¿� ����
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
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> money;

	arrNum = CheckAccount(id);
	if (arrNum == -1) {

		cout << "��ϵ��� ���� �����Դϴ�." << endl;
	}
	else {

		accArr[arrNum].money += money;
		cout << "�ԱݿϷ�" << endl;
	}
}

void WithdrawMoney() {

	int id;
	int money;
	int arrNum;

	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "��ݾ� : ";
	cin >> money;

	arrNum = CheckAccount(id);
	if (arrNum == -1) {

		cout << "��ϵ��� ���� �����Դϴ�." << endl;
	}
	else if (accArr[arrNum].money < money) {

		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else {

		accArr[arrNum].money -= money;
		cout << "��ݿϷ�" << endl;
	}
}

void ShowAllAccount() {

	for (int i = 0; i < accNum; i++) {

		cout << "����ID : " << accArr[i].accId << endl;
		cout << "�� �� : " << accArr[i].name << endl;
		cout << "�� �� : " << accArr[i].money << endl;
		cout << endl;
	}
}