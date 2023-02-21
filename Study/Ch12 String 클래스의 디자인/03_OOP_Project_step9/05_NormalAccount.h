/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : NormalAccount 클래스의 선언과 정의
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "03_Account.h"

class NormalAccount : public Account {

private:
	int interRate;

public:
	NormalAccount(int id, String name, int money, int rate);
	
	void Deposit(int money);
};

inline NormalAccount::NormalAccount(int id, String name, int money, int rate) 
	: Account(id, name, money), interRate(rate) { }

inline void NormalAccount::Deposit(int money) {

	Account::Deposit(money);	// 원금 추가
	Account::Deposit((int)((money * interRate) / 100.0));	// 이자 추가
}

#endif