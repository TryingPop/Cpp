/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	여러 개의 파일로 나누어서 코드를 관리

	헤더파일 : Account 클래스의 선언
*/

#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

class Account {

private:
	int accID;
	char* cusName;
	int balance;

public:
	Account(int ID, const char* name, int money);
	
	int GetAccID() const;
	void Withdraw(int money);
	virtual void Deposit(int money);
	virtual void ShowInfo() const = 0;

	~Account();
};
#endif