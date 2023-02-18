/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : HighCreditAccount 클래스 선언과 정의
*/

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "03_NormalAccount.h"
#include "09_BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {

private:
	int rank;

public:
	HighCreditAccount(int ID, const char* name, int money, int rate, int rank);

	void Deposit(int money);
	void ShowInfo() const;

	int GetRank() const;
};

inline HighCreditAccount::HighCreditAccount(int ID, const char* name, int money, int rate, int rank)
	: NormalAccount(ID, name, money, rate), rank(rank) { }

void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);	// 일반 이자 + 원금
	Account::Deposit((int)((GetRank() * money) / 100.0f));	// 신용 등급 이자
}

void HighCreditAccount::ShowInfo() const {

	NormalAccount::ShowInfo();
	cout << "신용등급(1toA, 2toB, 3toC): " << rank << endl;
}

int HighCreditAccount::GetRank() const {

	switch (rank) {

	case 1:
		return LEVEL_A;

	case 2:
		return LEVEL_B;

	case 3:
		return LEVEL_C;

	default:
		return 0;
	}
}
#endif
