/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : AccountHandler 클래스의 선언
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "06_HighCreditAccount.h"
#include "07_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray acc;
	int accNum;
	int choice;

public:
	AccountHandler();

	void Start();			// 프로그램 시작

	void ShowMenu();	// 기능 선택
	void SelectOpt();		// 기능에 따른 행동 실행

	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	
	int ChkAccID(int id);	// 중복 여부 확인

protected:
	void CreateNormal();
	void CreateHighCredit();
};

#endif