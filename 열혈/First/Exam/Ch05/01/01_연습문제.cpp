/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 교재 226p 문제1
	문제 04-3의 문제2를 통해서 NameCard 클래스를 정의하였다.
	그런데 이 클래스도 생성자 내에서 메모리 공간을 동적 할당하기 때문에
	복사 생성자가 필요한 클래스이다.
	이에 복사 생성자를 적절한 정의해보기를 바라며,
	복사 이후에 문제가 발생하지 않음을 다음 main 함수를 통해서 확인하기 바란다.

	main함수의 예
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

// 앞의 문제 참고안하고 문제 다시 풀기
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
			cout << "사원" << endl;
			break;

		case SENIOR:
			cout << "주임" << endl;
			break;

		case ASSIST: 
			cout << "대리" << endl;
			break;

		case MANAGER:
			cout << "과장" << endl;
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

		cout << "이름: " << name << endl;
		cout << "회사: " << comp << endl;
		cout << "전화번호: " << cp << endl;
		cout << "직급: ";
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