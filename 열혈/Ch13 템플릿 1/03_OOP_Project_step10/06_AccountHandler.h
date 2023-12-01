/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : AccountHandler 클래스의 선언
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "01_BoundCheckArray.h"
#include "02_Account.h"

class AccountHandler {

private:
	BoundCheckArray<Account*> accArr;
	int accNum;
	int choice;

public:
	AccountHandler();

	void Start(void);

	void ShowMenu(void);
	void SelectOpt(void);

	void CreateAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

	int GetAccIdx(int id) const;

protected:
	void CreateNormalAccount(void);
	void CreateHighCreditAccount(void);
};
#endif
