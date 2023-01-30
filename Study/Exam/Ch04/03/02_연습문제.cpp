/*
날짜 : 2023. 1. 30
이름 : 배성훈
내용 : 교재 190p 문제2
	명함을 의미하는 NameCard 클래스를 정의해보자.
	이 클래스에는 다음의 정보가 저장되어야 한다.
		- 성명
		- 회사이름
		- 전화번호
		- 직급
	
	단, 직급 정보를 제외한 나머지는 문자열의 형태로 저장을 하되,
	길이에 딱 맞는 메모리 공간을 할당 받는 형태로 정의하자(동적 할당하라는 의미이다).
	그리고 직급 정보는 int형 멤버변수를 선언해서 저장을 하되, 아래의 enum 선언을 활용해야 한다.
		enum {CLERK, SENIOR, ASSIST, MANAGER};
	
	위의 enum 선언에서 정의된 상수는 순서대로 사원, 주임, 대리, 과장을 뜻한다.
	그럼 다음 main 함수와 실행의 예를 참조하여,
	이 문제에서 원하는 형태대로 NameCard 클래스를 완성해보자.

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

	실행의 예
		이름: Lee
		회사: ABCEng
		전화번호: 010-1111-2222
		직급: 사원

		이름: Hong
		회사: OrangeEng
		전화번호: 010-3333-4444
		직급: 주임

		이름: Kim
		회사: SoGoodComp
		전화번호: 010-5555-6666
		직급: 대리

	참고로 이 문제의 ;해결의 위해서는 Chapter 03의 예제 RacingCarEnum.cpp를 참고하면 도움이 될 수 있다.
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

		cout << "이름: " << name << endl;
		cout << "회사: " << comp << endl;
		cout << "전화번호: " << cp << endl;
		
		const char* rk = (char*)malloc(5);
		
		// 이거 바꾸는걸 모르겠다
		switch (rank) {

		case COMP_POS::CLERK:
			rk = "사원";
			break;

		case COMP_POS::SENIOR:
			rk = "주임";
			break;

		case COMP_POS::ASSIST:
			rk = "대리";
			break;

		case COMP_POS::MANAGER:
			rk = "과장";
			break;
		}

		cout << "직급: " << rk << endl << endl;
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