/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : 공통헤더 및 상수 선언
*/

#ifndef __COMMON_H__
#define __COMMON_H__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 프로그램 기능 선택
enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 계좌 생성
enum { NORMAL = 1, HIGHCREDIT = 2 };

// 신용등급에 따른 이자율
enum { RANK_A = 7, RANK_B = 4, RANK_C = 2 };

#endif