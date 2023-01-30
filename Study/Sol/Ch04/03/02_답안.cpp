/*
��¥ : 2023. 1. 30
�̸� : �輺��
���� : ���� 190p ����2
	������ �ǹ��ϴ� NameCard Ŭ������ �����غ���.
	�� Ŭ�������� ������ ������ ����Ǿ�� �Ѵ�.
		- ����
		- ȸ���̸�
		- ��ȭ��ȣ
		- ����

	��, ���� ������ ������ �������� ���ڿ��� ���·� ������ �ϵ�,
	���̿� �� �´� �޸� ������ �Ҵ� �޴� ���·� ��������(���� �Ҵ��϶�� �ǹ��̴�).
	�׸��� ���� ������ int�� ��������� �����ؼ� ������ �ϵ�, �Ʒ��� enum ������ Ȱ���ؾ� �Ѵ�.
		enum {CLERK, SENIOR, ASSIST, MANAGER};

	���� enum ���𿡼� ���ǵ� ����� ������� ���, ����, �븮, ������ ���Ѵ�.
	�׷� ���� main �Լ��� ������ ���� �����Ͽ�,
	�� �������� ���ϴ� ���´�� NameCard Ŭ������ �ϼ��غ���.
	int main(void)
	{
		NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
		NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
		NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
		manClerk.ShowNameCardInfo();
		manSENIOR.ShowNameCardInfo();
		manAssist.ShowNameCardInfo();
		return 0;
	}
	������ ��
		�̸�: Lee
		ȸ��: ABCEng
		��ȭ��ȣ: 010-1111-2222
		����: ���
		�̸�: Hong
		ȸ��: OrangeEng
		��ȭ��ȣ: 010-3333-4444
		����: ����
		�̸�: Kim
		ȸ��: SoGoodComp
		��ȭ��ȣ: 010-5555-6666
		����: �븮
	����� �� ������ ;�ذ��� ���ؼ��� Chapter 03�� ���� RacingCarEnum.cpp�� �����ϸ� ������ �� �� �ִ�.
*/

#define _CRT_SECURE_NO_WARNINGS		// strcpy ����ϱ� ���� ����
#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS {

	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos) {

		switch (pos) {

		case CLERK:
			cout << "���" << endl;
			break;

		case SENIOR:
			cout << "����" << endl;
			break;

		case ASSIST:
			cout << "�븮" << endl;
			break;

		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}

class NameCard {
	
private:
	char* name;
	char* company;
	char* phone;
	int position;

public:
	NameCard(const char* _name, const char* _company, const char* _phone, int pos) 
		: position(pos) {

		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}

	void ShowNameCardInfo() {

		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}

	~NameCard() {

		delete[] name;
		delete[] company;
		delete[] phone;
	}
};

int main(void) 
{

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}