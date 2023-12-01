/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 629p

	헤더파일 : MinusException 클래스의 선언과 정의, InsuffException 클래스의 선언과 정의
*/

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "10_BankingCommonDecl.h"

class MinusException {

private:
	int exval;	// 예외의 원인이 되는 금액

public:
	MinusException(int val) 
		: exval(val) { }

	void ShowExceptionInfo(void) const {

		cout << "입(출)금액" << exval << "은 유효하지 않습니다!" << endl;
	}
};

class InsuffException {

private:
	int balance;	// 현재 잔액
	int reqval;		// 출금 요구액

public:
	InsuffException(int val, int req)
		: balance(val), reqval(req) { }

	void ShowExceptionInfo(void) const {

		cout << "잔액에서 " << reqval - balance << "가 부족합니다!" << endl;
	}
};

#endif
