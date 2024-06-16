/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : 공토헤더 및 상수선언
*/

#ifndef __COMMON_H__
#define __COMMON_H__

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// 프로그램 선택 메뉴
enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 계좌 생성
enum { NORMAL = 1, HIGHCREDIT = 2 };

// 신용등급에 따른 이자
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

#endif
