/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더 파일 : HighCreditAccount 클래스 선언과 정의
*/

#ifndef __HIGHCREDIT_H_
#define __HIGHCREDIT_H_

#define _CRT_SECURE_NO_WARNINGS
#include "03_NormalAccount.h"
#include "07_BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {

private:
	int rank;

public:
	HighCreditAccount(int ID, const char* name, int money, int inter, int rank);

	virtual void Deposit(int money);
	void ShowInfo() const;

	virtual int GetRank() const ;
	int GetRankInter(int money);
};

inline HighCreditAccount::HighCreditAccount(int ID, const char* name, int money, int inter, int rank)
	: NormalAccount(ID, name, money, inter), rank(rank) { }

inline void HighCreditAccount::Deposit(int money) {

	NormalAccount::Deposit(money);
	Account::Deposit(GetRankInter(money));
}

inline void HighCreditAccount::ShowInfo() const {

	NormalAccount::ShowInfo();
	cout << "신용등급(1toA, 2toB, 3toC): " << rank << endl;
}


inline int HighCreditAccount::GetRank() const {

	switch (rank) {

	case RANK::A:
		return 30;

	case RANK::B:
		return 20;

	case RANK::C:
		return 10;

	default:
		return 0;
	}
}

inline int HighCreditAccount::GetRankInter(int money) {

	return (int)(money * (GetRank() / 100.0f));
}
#endif
