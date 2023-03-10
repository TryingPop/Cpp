/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 397p

	헤더파일 : 공통헤더 및 상수선언
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

#endif
