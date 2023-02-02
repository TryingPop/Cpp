/*
날짜 : 2023. 2. 2
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {

	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos) {

		switch (pos) {

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
	}
}

class NameCard {

private:
	char* name;
	char* company;
	char* phone;
	int position;

public:
	NameCard(const char* name, const char* company, const char* phone, int pos) 
		: position(pos) {

		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}

	NameCard(const NameCard& ref) 
		: position(ref.position) {
		name = new char[strlen(ref.name) + 1];
		company = new char[strlen(ref.company) + 1];
		phone = new char[strlen(ref.phone) + 1];

		strcpy(name, ref.name);
		strcpy(company, ref.company);
		strcpy(phone, ref.phone);
	}

	void ShowNameCardInfo() {

		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
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

	NameCard manClerk("Lee", "ABCEng", "010-111102222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}