/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : NormalAccount 클래스 선언과 정의
*/

#ifndef __NORMAL_H_
#define __NORMAL_H_

#define _CRT_SECURE_NO_WARNINGS
#include "01_Account.h"
#include "07_BankingCommonDecl.h"

class NormalAccount : public Account {

private:
	int interRate;	// 이자율

public:
	NormalAccount(int ID, const char* name, int money, int inter);

	virtual void Deposit(int money);
	void ShowInfo() const;
};

// 인라인이 빠르다고 하고 헤더이므로 인라인으로 정의
inline NormalAccount::NormalAccount(int ID, const char* name, int money, int inter)
	: Account(ID, name, money), interRate(inter) { }

inline void NormalAccount::Deposit(int money) {

	money += (int)((interRate * money) / 100.0f);
	Account::Deposit(money);
}

inline void NormalAccount::ShowInfo() const {

	Account::ShowInfo();
	cout << "이자율: " << interRate << endl;
}

#endif
