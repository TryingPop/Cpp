/*
날짜 : 2023. 2. 18
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : AccountHandler 클래스의 선언
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "05_AccountArray.h"

class AccountHandler {

private:
	BoundCheckAccountPtrArray accArr;
	int accNum;
	int choice;

public:
	AccountHandler(int len);

	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllInfo() const;

	void Start();

	void ShowMenu();
	void SelectOpt();

	~AccountHandler();

protected:
	void CreateNormal();
	void CreateHighCredit();
};

#endif
