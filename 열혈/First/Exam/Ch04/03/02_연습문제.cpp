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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {

	enum {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard {

private:
	char* name;
	char* comp;
	char* cp;
	int rank;

public:
	NameCard(const char* name, const char* comp, const char* cp, int rank)
		: rank(rank) {

		this->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		strcpy(this->name, name);

		this->comp = new char[strlen(comp) + 1];
		strcpy(this->comp, comp);

		this->cp = (char*)malloc(sizeof(char) * (strlen(cp) + 1));
		strcpy(this->cp, cp);
	}

	void ShowNameCardInfo() const {

		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comp << endl;
		cout << "��ȭ��ȣ: " << cp << endl;
		
		const char* rk = (char*)malloc(5);
		
		// �̰� �ٲٴ°� �𸣰ڴ�
		switch (rank) {

		case COMP_POS::CLERK:
			rk = "���";
			break;

		case COMP_POS::SENIOR:
			rk = "����";
			break;

		case COMP_POS::ASSIST:
			rk = "�븮";
			break;

		case COMP_POS::MANAGER:
			rk = "����";
			break;
		}

		cout << "����: " << rk << endl << endl;
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