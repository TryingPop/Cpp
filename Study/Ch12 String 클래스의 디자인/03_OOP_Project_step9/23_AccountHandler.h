/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 496p

	헤더파일 : AccountHandler의 선언
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "13_Account.h"
#include "20_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray accArr;
	int accNum;

public:
	AccountHandler();

	void ShowMenu(void) const;

	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
};
#endif