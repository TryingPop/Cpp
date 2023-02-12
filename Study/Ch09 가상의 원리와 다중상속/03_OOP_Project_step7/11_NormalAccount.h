/*
날짜 : 2023. 2. 12
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 393p

	헤더파일 : NormalAccount 클래스 선언과 정의
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "09_Account.h"

class NormalAccount : public Account {

private:
	int interRate;	// 이자율 % 단위

public:
	NormalAccount(int ID, int money, char* name, int rate)
		: Account(ID, money, name), interRate(rate) { }

	virtual void Deposit(int money) {


		Account::Deposit(money);	// 원금 추가
		Account::Deposit(money * (interRate / 100.0));	// 이자 추가
	}
};
#endif