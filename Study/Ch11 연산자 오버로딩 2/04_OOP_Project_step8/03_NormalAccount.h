/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : NormalAccount 클래스 선언과 정의
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "01_Account.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int ID, const char* name, int money, int rate);

	void Deposit(int money);
	void ShowInfo() const;
};

inline NormalAccount::NormalAccount(int ID, const char* name, int money, int rate)
	: Account (ID, name, money), interRate(rate) { }

inline void NormalAccount::Deposit(int money) {

	Account::Deposit(money);	// 원금
	Account::Deposit((int)((money * interRate) / 100.0f));	// 이자
}

inline void NormalAccount::ShowInfo() const {

	Account:ShowInfo();
	cout << "이자율: " << interRate << endl;
} 
#endif
