/*
날짜 : 2023. 2. 18
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : 공통헤더 및 상수 선언들
*/

#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__


enum { NORMAL = 1, HIGHCREDIT };	// 계좌 생성

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };	// 프로그램

enum { LEVEL_A = 7, LEVEL_B = 3, LEVEL_C = 2 };	// 신용 등급

#endif