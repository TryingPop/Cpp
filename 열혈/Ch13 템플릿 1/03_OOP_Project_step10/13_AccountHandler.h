/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 555p

	헤더파일 : AccountHandler 클래스의 선언
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "14_Account.h"
#include "12_BoundCheckArray.h"

class AccountHandler {

private:
	BoundCheckArray<Account*> accArr;
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
	void MakeCreditAccount(void);
};

#endif