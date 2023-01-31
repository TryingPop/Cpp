/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���� 226p ����1
	���� 04-3�� ����2�� ���ؼ� NameCard Ŭ������ �����Ͽ���.
	�׷��� �� Ŭ������ ������ ������ �޸� ������ ���� �Ҵ��ϱ� ������
	���� �����ڰ� �ʿ��� Ŭ�����̴�.
	�̿� ���� �����ڸ� ������ �����غ��⸦ �ٶ��,
	���� ���Ŀ� ������ �߻����� ������ ���� main �Լ��� ���ؼ� Ȯ���ϱ� �ٶ���.

	main�Լ��� ��
	int main(void)
	{

		NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
		NameCard copy1 = manClerk;
		NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
		NameCard copy2 = manSENIOR;
		copy1.ShowNameCardInfo();
		copy2.ShowNameCardInfo();
		return 0;
	}
*/

// ���� ���� ������ϰ� ���� �ٽ� Ǯ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {

	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowRank(int rank) {

		switch (rank)
		{

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

		cout << endl;
	}
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
		this->comp = (char*)malloc(sizeof(char) * (strlen(comp) + 1));
		this->cp = (char*)malloc(sizeof(char) * (strlen(cp) + 1));

		strcpy(this->name, name);
		strcpy(this->comp, comp);
		strcpy(this->cp, cp);
	}

	NameCard(const NameCard& copy) 
		: rank(copy.rank) {

		name = new char[strlen(copy.name) + 1];
		comp = new char[strlen(copy.comp) + 1];
		cp = new char[strlen(copy.cp) + 1];

		strcpy(name, copy.name);
		strcpy(comp, copy.comp);
		strcpy(cp, copy.cp);
	}

	void ShowNameCardInfo() {

		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comp << endl;
		cout << "��ȭ��ȣ: " << cp << endl;
		cout << "����: ";
		COMP_POS::ShowRank(rank);
	}

	~NameCard() {

		free(name);
		free(comp);
		free(cp);
	}
};

int main(void) 
{

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}