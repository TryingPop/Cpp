/*
��¥ : 2023. 2. 11
�̸� : �輺��
���� : ������� ���� ���α׷�
	��� ���� : ������� �� ��� �����
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
