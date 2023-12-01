/*
날짜 : 2023. 2. 11
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더 파일 : 공통헤더 및 상수 선언들
*/

#ifndef __COMMON_H_
#define __COMMON_H_
#include <iostream>
#include <cstring>

using namespace std;

namespace RANK {

	enum { A = 1, B, C };
}

namespace SELECT_ACC {

	enum {NORMAL = 1, HIGHCREDIT};
}

namespace SELECT_OPT {

	enum {CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
}

#endif
